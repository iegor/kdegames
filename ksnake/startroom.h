/**
 * Copyright Michel Filippi <mfilippi@sade.rhein-main.de>
 *           Robert Williams
 *           Andrew Chant <andrew.chant@utoronto.ca>
 *           André Luiz dos Santos <andre@netvision.com.br>
 *           Benjamin Meyer <ben+ksnake@meyerhome.net>
 *
 * This file is part of the ksnake package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef STARTROOM_H
#define STARTROOM_H

#include <qwidget.h>

class QLabel;
class QSpinBox;

class StartRoom : public QWidget
{
	Q_OBJECT
public:
	StartRoom( QWidget *parent=0, const char *name=0 );

private slots:
	void loadLevel(int level);

private:
	QLabel       *picture;
	QSpinBox   *roomRange;

};

#endif // STARTROOM_H
