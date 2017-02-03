/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2017 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_PROXYPROPERTIESDIALOG_H
#define OTTER_PROXYPROPERTIESDIALOG_H

#include "../Dialog.h"
#include "../../core/NetworkManagerFactory.h"

namespace Otter
{

namespace Ui
{
	class ProxyPropertiesDialog;
}

class ProxyPropertiesDialog : public Dialog
{
	Q_OBJECT

public:
	explicit ProxyPropertiesDialog(const ProxyDefinition &proxy, QWidget *parent = nullptr);
	~ProxyPropertiesDialog();

	ProxyDefinition getProxy() const;

protected:
	void changeEvent(QEvent *event);

private:
	ProxyDefinition m_proxy;
	Ui::ProxyPropertiesDialog *m_ui;
};

}

#endif
