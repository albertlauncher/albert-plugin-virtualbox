// albert - a simple application launcher for linux
// Copyright (C) 2016-2017 Martin Buergmann
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include "core/item.h"

namespace VirtualBox {

class VMItem : public Core::Item
{
public:
    VMItem(const QString &name,
           const QString &uuid,
           int &mainAction,
           const std::vector<Core::Action> actions,
           const QString &state);


    /*
     * Implementation of AlbertItem interface
     */

    QString id() const override { return idstring_; }
    QString text() const override { return name_; }
    QString subtext() const override;
    QString iconPath() const override { return iconPath_; }
    std::vector<Core::Action> actions() override { return actions_; }

    /*
     * Item specific members
     */

    static QString iconPath_;
    static const int VM_START;
    static const int VM_PAUSE;
    static const int VM_RESUME;
    static const int VM_STATE_CHANGING;
    static const int VM_DIFFERENT;

private:
    QString name_;
    QString uuid_;
    QString idstring_;
    std::vector<Core::Action> actions_;
    int mainAction_;
};

} // namespace VirtualBox
