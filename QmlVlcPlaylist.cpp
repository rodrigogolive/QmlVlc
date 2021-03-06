/*******************************************************************************
* Copyright (c) 2014, Sergey Radionov <rsatom_gmail.com>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.

* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include "QmlVlcPlaylist.h"

#include <QStringList>

#include "QmlVlcConfig.h"

unsigned int QmlVlcPlaylist::get_itemCount()
{
    return m_player.item_count();
}

bool QmlVlcPlaylist::get_isPlaying()
{
    return m_player.is_playing();
}

int QmlVlcPlaylist::get_current()
{
    return m_player.current_item();
}

int QmlVlcPlaylist::add( const QString& mrl )
{
    return m_player.add_media( mrl.toUtf8().data() );
}

int QmlVlcPlaylist::addWithOptions( const QString& mrl, const QStringList& options )
{
    QList<QByteArray> bufStorage;
    std::vector<const char*> trusted_opts;
    std::vector<const char*> untrusted_opts;

    for( int i = 0; i < options.size(); ++i ) {
        QByteArray& buf = *bufStorage.insert( bufStorage.end(), options[i].toUtf8() );
        if( QmlVlcConfig::trustedEnvironment() )
            trusted_opts.push_back( buf.data() );
        else
            untrusted_opts.push_back( buf.data() );
    }

    const char** untrusted_optv = untrusted_opts.empty() ? 0 : &untrusted_opts[0];
    const char** trusted_optv = trusted_opts.empty() ? 0 : &trusted_opts[0];
    return m_player.add_media( mrl.toUtf8().data(),
                               untrusted_opts.size(), untrusted_optv,
                               trusted_opts.size(), trusted_optv );
}

void QmlVlcPlaylist::play()
{
    m_player.play();
}

bool QmlVlcPlaylist::playItem( unsigned int idx )
{
    return m_player.play( idx );
}

void QmlVlcPlaylist::setCurrentItem( unsigned int idx )
{
    m_player.set_current( idx );
}

void QmlVlcPlaylist::pause()
{
    m_player.pause();
}

void QmlVlcPlaylist::togglePause()
{
    if ( m_player.is_playing() ) m_player.pause();
    else m_player.play();
}

void QmlVlcPlaylist::stop()
{
    //use async stop to avoid freeze (on network timeout for example).
    m_player.stop( true );
}

void QmlVlcPlaylist::next()
{
    m_player.next();
}

void QmlVlcPlaylist::prev()
{
    m_player.prev();
}

void QmlVlcPlaylist::clear()
{
    m_player.clear_items();
}

bool QmlVlcPlaylist::removeItem( unsigned int idx )
{
    return m_player.delete_item( idx );
}
