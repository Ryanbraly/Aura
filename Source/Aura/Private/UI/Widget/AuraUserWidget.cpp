// Copyright my own damn self, it's just a learning project


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetcontroller)
{
	WidgetController = InWidgetcontroller;
	WidgetControllerSet();
}
