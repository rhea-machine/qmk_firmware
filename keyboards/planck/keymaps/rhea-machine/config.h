/* Copyright (C) 2024  Rhéa Santos
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef AUDIO_ENABLE
#    define AUDIO_INIT_DELAY
#    define ONE_UP_SOUND Q__NOTE(_E6 ), Q__NOTE(_G6 ), Q__NOTE(_E7 ), Q__NOTE(_C7 ), Q__NOTE(_D7 ), Q__NOTE(_G7 )
#    define STARTUP_SONG SONG(ONE_UP_SOUND)
#    define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), SONG(DVORAK_SOUND) }
#endif

