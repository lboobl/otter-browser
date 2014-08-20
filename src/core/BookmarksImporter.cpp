/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2014 Piotr Wójcik <chocimier@tlen.pl>
* Copyright (C) 2014 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
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
*
**************************************************************************/

#include "BookmarksImporter.h"
#include "BookmarksManager.h"
#include "BookmarksModel.h"

namespace Otter
{

BookmarksImporter::BookmarksImporter(QObject *parent): Importer(parent),
	m_importFolder(NULL),
	m_currentFolder(NULL),
	m_allowDuplicates(true)
{
}

void BookmarksImporter::goToParent()
{
	if (m_currentFolder == m_importFolder)
	{
		return;
	}

	if (m_currentFolder)
	{
		m_currentFolder = m_currentFolder->parent();
	}
	else
	{
		m_currentFolder = BookmarksManager::getModel()->getRootItem();
	}
}

void BookmarksImporter::removeAllBookmarks()
{
	BookmarksManager::getModel()->getRootItem()->removeRows(0, BookmarksManager::getModel()->getRootItem()->rowCount());
}

void BookmarksImporter::setAllowDuplicates(bool allow)
{
	m_allowDuplicates = allow;
}

void BookmarksImporter::setCurrentFolder(QStandardItem *folder)
{
	m_currentFolder = folder;
}

void BookmarksImporter::setImportFolder(QStandardItem *folder)
{
	m_importFolder = folder;
	m_currentFolder = folder;
}

QStandardItem *BookmarksImporter::getCurrentFolder()
{
	return m_currentFolder;
}

ImportType BookmarksImporter::getType() const
{
	return BookmarksImport;
}

bool BookmarksImporter::allowDuplicates() const
{
	return m_allowDuplicates;
}

}
