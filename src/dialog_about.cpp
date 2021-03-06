/****************************************************************************
** Copyright (c) 2016, Fougue Ltd. <http://www.fougue.pro>
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
**     1. Redistributions of source code must retain the above copyright
**        notice, this list of conditions and the following disclaimer.
**
**     2. Redistributions in binary form must reproduce the above
**        copyright notice, this list of conditions and the following
**        disclaimer in the documentation and/or other materials provided
**        with the distribution.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
****************************************************************************/

#include "dialog_about.h"

#include "ui_dialog_about.h"
#include <Standard_Version.hxx>
#include <gmio_core/version.h>

namespace Mayo {

DialogAbout::DialogAbout(QWidget *parent)
    : QDialog(parent),
      m_ui(new Ui_DialogAbout)
{
    m_ui->setupUi(this);

    m_ui->label_Version->setText(
                m_ui->label_Version->text().arg("0.1-dev").arg(QT_POINTER_SIZE * 8));
    m_ui->label_BuildDateTime->setText(
                m_ui->label_BuildDateTime->text().arg(__DATE__).arg(__TIME__));
    m_ui->label_Qt->setText(m_ui->label_Qt->text().arg(QT_VERSION_STR));
    m_ui->label_Occ->setText(m_ui->label_Occ->text().arg(OCC_VERSION_COMPLETE));
    m_ui->label_Gmio->setText(m_ui->label_Gmio->text().arg(GMIO_VERSION_STR));
}

DialogAbout::~DialogAbout()
{
    delete m_ui;
}

} // namespace Mayo
