/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of Pingnoo
 *
 * Created by Adrian Carpenter on 18/12/2020.
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

#include "ColourDialog.h"

#include <QColorDialog>

Nedrysoft::RouteAnalyser::ColourDialog::ColourDialog() :
        m_colourDialog(nullptr) {

}

Nedrysoft::RouteAnalyser::ColourDialog::~ColourDialog() {
    if (m_colourDialog) {
        delete m_colourDialog;
    }
}

void Nedrysoft::RouteAnalyser::ColourDialog::close() {
    if (m_colourDialog) {
        delete m_colourDialog;

        m_colourDialog = nullptr;
    }
};


Nedrysoft::RouteAnalyser::ColourDialog *Nedrysoft::RouteAnalyser::ColourDialog::getInstance() {
    static ColourDialog *instance = nullptr;

    if (instance==nullptr) {
        instance = new  ColourDialog;
    }

    return instance;
}

void Nedrysoft::RouteAnalyser::ColourDialog::open(QColor initialColour, QString title, ColourFunction colourFunction) {
    if (m_colourDialog) {
        delete m_colourDialog;
    }

    m_colourDialog = new QColorDialog;

    m_colourDialog->setWindowTitle(title);
    m_colourDialog->setCurrentColor(initialColour);

    m_colourDialog->open();

    connect(m_colourDialog, &QColorDialog::colorSelected, [=](const QColor &colour) {
        colourFunction(colour);
    });
}
