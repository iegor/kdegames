/***************************************************************************
                          lskatview.h  -  description
                             -------------------
    begin                : Tue May  2 15:47:11 CEST 2000
    copyright            : (C) 2000 by Martin Heni
    email                : martin@heni-online.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef LSKATVIEW_H
#define LSKATVIEW_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif 

#include <qwidget.h>
#include <qrect.h>
#include "lskat.h"

class LSkatDoc;

/** The LSkatView class provides the view widget for the LSkatApp instance.
 * The View instance inherits QWidget as a base class and represents the view object of a KTMainWindow. As LSkatView is part of the
 * docuement-view model, it needs a reference to the document object connected with it by the LSkatApp class to manipulate and display
 * the document structure provided by the LSkatDoc class.
 * 
 * @author Source Framework Automatically Generated by KDevelop, (c) The KDevelop Team.
 * @version KDevelop version 0.4 code generation
 */
class LSkatView : public QWidget
{
  Q_OBJECT
  public:
  /** Constructor for the main view */
  LSkatView(QWidget *parent = 0, const char *name=0);

  /** returns a pointer to the document connected to the view instance. Mind that this method requires a LSkatApp instance as a parent
   * widget to get to the window document pointer by calling the LSkatApp::getDocument() method.
   *
   * @see LSkatApp#getDocument
   */
  LSkatDoc *getDocument() const;

  void paintEvent( QPaintEvent * p);
  void Paint(QPainter *p);
  void InitMove(int player,int x,int y);
  void updateStatus();

  protected:
  void drawDeck(QPainter *p);
  void drawIntro(QPainter *p);
  void drawMove(QPainter *p);
  void drawStatus(QPainter *p);
  void drawFinal(QPainter *p);
  void drawBorder(QPainter *p,QRect rect,int offset,int width,int mode);
  QPoint calcCardPos(int x,int y);

  void mousePressEvent ( QMouseEvent *m );

  protected slots:
  void moveTimerReady();
  void introTimerReady();
  void drawTabText(QPainter *p,QRect rect,QString s,int *ts);


  private:
  QRect status_rect1;
  QRect status_rect2;
  QRect status_rect3;
  QTimer *moveTimer;
  QTimer *introTimer;
  int introcnt;
  int cardmovecnt;
  int cardmovex,cardmovey;
  int cardmoveunder;
  QPoint cardorigin;
  QPoint cardend;
  int introCards[NO_OF_CARDS];

};

#endif // LSKATVIEW_H