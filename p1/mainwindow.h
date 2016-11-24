#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <X11/Intrinsic.h>
#include <Xm/Xm.h>
#include <Xm/Protocols.h>
#include <Xm/MainW.h>
#include <Xm/Form.h>
#include <Xm/Frame.h>
#include <Xm/DrawingA.h>
#include <Xm/PushB.h>
#include <Xm/RowColumn.h>
#include <Xm/PushBG.h>
#include <Xm/CascadeB.h>
#include <Xm/ToggleB.h>
#include <Xm/ComboBox.h>
#include <Xm/Scale.h>
#include <Xm/Label.h>
#include <Xm/MessageB.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "colors.h"
#include "lines.h"
#include "quitdialog.h"

class MainWindow
{
public:
  MainWindow(int argc, char **argv);
  ~MainWindow();
  int run();

  static void OnQuit(Widget w, XtPointer client_data, XtPointer call_data);
  static void ClearCB(Widget w, XtPointer client_data, XtPointer call_data);
  static void ExposeCB(Widget w, XtPointer client_data, XtPointer call_data);
  static void DrawLineCB(Widget w, XtPointer client_data, XtPointer call_data);
  static void InputLineEH(Widget w, XtPointer client_data, XEvent *event,
    Boolean *cont);
  static void OnShapeToggled(Widget w, XtPointer client_data,
    XtPointer call_data);
  static void OnBorderToggled(Widget w, XtPointer client_data,
    XtPointer call_data);
  static void OnFillToggled(Widget w, XtPointer client_data,
    XtPointer call_data);
  static void OnColorChanged(Widget w, XtPointer client_data,
    XtPointer call_data);
  static void OnLineWidthChanged(Widget w, XtPointer client_data,
    XtPointer call_data);

private:
  static Lines *m_lines;       // array of line descriptors
  static GC m_draw_gc;         // GC used for final drawing
  static GC m_input_gc;        // GC used for drawing current position
  static int m_button_pressed; // input state
  static int x1, y1, x2, y2;   // input coords

  static const int SHAPE_POINT   = 0;
  static const int SHAPE_LINE    = 1;
  static const int SHAPE_RECT    = 2;
  static const int SHAPE_ELLIPSE = 3;
  static const int BORDER_FULL   = 0;
  static const int BORDER_DOTTED = 1;
  static int m_shape;
  static int m_border;
  static bool m_fill;
  static int m_line_width;

  static QuitDialog *m_quitdlg;

  Atom wm_delete;

  Widget m_top_level;
  Widget m_main_win;
  Widget m_frame;
  Widget m_draw_area;
  Widget m_tools;
  Widget m_tools_shapes;
  Widget m_tools_border;
  Widget m_tools_style;

  // Menu
  Widget   m_menu_bar;
  Widget   m_menu;
  Widget   m_menu_w;
  Widget   m_menu_clear_btn;
  Widget   m_menu_exit_btn;
  Widget   m_menu_cascade;
  XmString m_menu_label;
  XmString m_menu_accel;

  // Tools
  static Widget m_shape_point;
  static Widget m_shape_line;
  static Widget m_shape_rect;
  static Widget m_shape_ellipse;
  static Widget m_border_full;
  static Widget m_border_dotted;
  static Widget m_fill_btn;
  static Widget m_line_width_sc;
  static Widget m_fg_cb;
  static Widget m_bg_cb;
  Widget m_fg_label;
  Widget m_bg_label;

  XtAppContext m_app_context;

  void ShowQuitDialog();
  void CreateMenu();
  void CreateTools();
};

#endif // MAINWINDOW_H
