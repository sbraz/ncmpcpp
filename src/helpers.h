/***************************************************************************
 *   Copyright (C) 2008 by Andrzej Rybczak   *
 *   electricityispower@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef HAVE_HELPERS_H
#define HAVE_HELPERS_H

#include "mpdpp.h"
#include "ncmpcpp.h"
#include "settings.h"

bool ConnectToMPD();
bool ParseArgv(int, char **);

void LockStatusbar();
void UnlockStatusbar();

class CaseInsensitiveSorting
{
	public:
		bool operator()(string, string);
		bool operator()(Song *, Song *);
		bool operator()(const MPD::Item &, const MPD::Item &);
};

template <class T> void GenericDisplayer(const T &t, void *, Menu<T> *menu)
{
	*menu << t;
}

bool SortSongsByTrack(Song *, Song *);

void UpdateSongList(Menu<Song> *);

bool Keypressed(int, const int *);

void WindowTitle(const string &);
void EscapeUnallowedChars(string &);

string IntoStr(mpd_TagItems);
string FindSharedDir(const string &, const string &);
string TotalPlaylistLength();
void DisplayStringPair(const StringPair &, void *, Menu<StringPair> *);
string DisplayColumns(string);
void DisplaySongInColumns(const Song &, void *, Menu<Song> *);
void DisplaySong(const Song &, void * = &Config.song_list_format, Menu<Song> * = NULL);
void GetInfo(Song &, Scrollpad &);
void ShowMessage(const char *, ...);

#endif

