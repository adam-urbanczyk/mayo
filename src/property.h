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

#pragma once

#include <QtCore/QString>
#include <vector>

namespace Mayo {

class Property;
class PropertyEnumeration;

class PropertyOwner
{
public:
    const std::vector<Property*>& properties() const;

protected:
    virtual void onPropertyChanged(Property* prop);
    void blockPropertyChanged(bool on);
    bool isPropertyChangedBlocked() const;

    void addProperty(Property* prop);

    struct PropertyChangedBlocker {
        PropertyChangedBlocker(PropertyOwner* owner);
        ~PropertyChangedBlocker();
        PropertyOwner* const m_owner;
    };

private:
    friend class Property;
    friend struct PropertyChangedBlocker;
    std::vector<Property*> m_properties;
    bool m_propertyChangedBlocked = false;
};

#define Mayo_PropertyChangedBlocker(owner) \
            PropertyChangedBlocker __Mayo_PropertyChangedBlocker(owner); \
            Q_UNUSED(__Mayo_PropertyChangedBlocker);

class Property
{
public:
    Property(PropertyOwner* owner, const QString& label);
    Property() = delete;
    Property(const Property&) = delete;
    Property(Property&&) = delete;
    Property& operator=(const Property&) = delete;
    Property& operator=(Property&&) = delete;

    const QString& label() const;

    virtual const char* dynTypeName() const = 0;

    static const char BoolTypeName[];
    static const char IntTypeName[];
    static const char DoubleTypeName[];
    static const char QByteArrayTypeName[];
    static const char QStringTypeName[];
    static const char QDateTimeTypeName[];
    static const char EnumerationTypeName[];
    static const char OccColorTypeName[];

protected:
    void notifyChanged();

private:
    PropertyOwner* const m_owner = nullptr;
    const QString m_label;
};

} // namespace Mayo
