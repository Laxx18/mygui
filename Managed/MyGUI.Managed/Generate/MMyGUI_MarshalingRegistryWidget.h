   mCreators->Add(gcnew System::String("Button"), gcnew HandleCreator(IButton::WidgetCreator));
   mCreators->Add(gcnew System::String("Canvas"), gcnew HandleCreator(ICanvas::WidgetCreator));
   mCreators->Add(gcnew System::String("ComboBox"), gcnew HandleCreator(IComboBox::WidgetCreator));
   mCreators->Add(gcnew System::String("DDContainer"), gcnew HandleCreator(IDDContainer::WidgetCreator));
   mCreators->Add(gcnew System::String("Edit"), gcnew HandleCreator(IEditBox::WidgetCreator));
   mCreators->Add(gcnew System::String("HScroll"), gcnew HandleCreator(IHScrollBar::WidgetCreator));
   mCreators->Add(gcnew System::String("ItemBox"), gcnew HandleCreator(IItemBox::WidgetCreator));
   mCreators->Add(gcnew System::String("List"), gcnew HandleCreator(IListBox::WidgetCreator));
   mCreators->Add(gcnew System::String("MenuBar"), gcnew HandleCreator(IMenuBar::WidgetCreator));
   mCreators->Add(gcnew System::String("MenuCtrl"), gcnew HandleCreator(IMenuCtrl::WidgetCreator));
   mCreators->Add(gcnew System::String("Message"), gcnew HandleCreator(IMessageBox::WidgetCreator));
   mCreators->Add(gcnew System::String("MultiList"), gcnew HandleCreator(IMultiListBox::WidgetCreator));
   mCreators->Add(gcnew System::String("PopupMenu"), gcnew HandleCreator(IPopupMenu::WidgetCreator));
   mCreators->Add(gcnew System::String("Progress"), gcnew HandleCreator(IProgressBar::WidgetCreator));
   mCreators->Add(gcnew System::String("RenderBox"), gcnew HandleCreator(IRenderBox::WidgetCreator));
   mCreators->Add(gcnew System::String("ScrollView"), gcnew HandleCreator(IScrollView::WidgetCreator));
   mCreators->Add(gcnew System::String("StaticImage"), gcnew HandleCreator(IStaticImage::WidgetCreator));
   mCreators->Add(gcnew System::String("StaticText"), gcnew HandleCreator(IStaticText::WidgetCreator));
   mCreators->Add(gcnew System::String("Tab"), gcnew HandleCreator(ITabBar::WidgetCreator));
   mCreators->Add(gcnew System::String("VScroll"), gcnew HandleCreator(IVScrollBar::WidgetCreator));
   mCreators->Add(gcnew System::String("Widget"), gcnew HandleCreator(IWidget::WidgetCreator));
   mCreators->Add(gcnew System::String("Window"), gcnew HandleCreator(IWindow::WidgetCreator));
   mCreators->Add(gcnew System::String("MenuItem"), gcnew HandleCreator(IMenuItem::WidgetCreator));
   mCreators->Add(gcnew System::String("TabItem"), gcnew HandleCreator(ITabItem::WidgetCreator));
