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

#ifndef QMLVLCMEDIADESC_H
#define QMLVLCMEDIADESC_H

#include <QObject>

#include "libvlc_wrapper/vlc_player.h"

#include <QObject>

class QmlVlcMediaDesc : public QObject
{
    Q_OBJECT
public:
    QmlVlcMediaDesc( vlc::player& player )
        : m_player( player ) {}

    Q_PROPERTY( QString title READ get_title )
    Q_PROPERTY( QString artist READ get_artist )
    Q_PROPERTY( QString genre READ get_genre )
    Q_PROPERTY( QString copyright READ get_copyright )
    Q_PROPERTY( QString album READ get_album )
    Q_PROPERTY( QString trackNumber READ get_trackNumber )
    Q_PROPERTY( QString description READ get_description )
    Q_PROPERTY( QString rating READ get_rating )
    Q_PROPERTY( QString date READ get_date )
    Q_PROPERTY( QString setting READ get_setting )
    Q_PROPERTY( QString URL READ get_URL )
    Q_PROPERTY( QString language READ get_language )
    Q_PROPERTY( QString nowPlaying READ get_nowPlaying )
    Q_PROPERTY( QString publisher READ get_publisher )
    Q_PROPERTY( QString encodedBy READ get_encodedBy )
    Q_PROPERTY( QString artworkURL READ get_artworkURL )
    Q_PROPERTY( QString trackID READ get_trackID )

    QString get_title();
    QString get_artist();
    QString get_genre();
    QString get_copyright();
    QString get_album();
    QString get_trackNumber();
    QString get_description();
    QString get_rating();
    QString get_date();
    QString get_setting();
    QString get_URL();
    QString get_language();
    QString get_nowPlaying();
    QString get_publisher();
    QString get_encodedBy();
    QString get_artworkURL();
    QString get_trackID();

private:
    QString get_meta( libvlc_meta_t e_meta );

private:
    vlc::player& m_player;
};

#endif // QMLVLCMEDIADESC_H
