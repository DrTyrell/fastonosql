/*  Copyright (C) 2014-2016 FastoGT. All right reserved.

    This file is part of FastoNoSQL.

    FastoNoSQL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoNoSQL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoNoSQL.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "gui/upscaledb/connection_widget.h"

#include "core/upscaledb/connection_settings.h"

#include "core/connection_settings/iconnection_settings_local.h"

namespace fastonosql {
namespace gui {
namespace upscaledb {

ConnectionWidget::ConnectionWidget(QWidget* parent) : ConnectionLocalWidget(false, parent) {}

void ConnectionWidget::syncControls(core::IConnectionSettingsBase* connection) {
  core::IConnectionSettingsLocal* local = static_cast<core::IConnectionSettingsLocal*>(connection);
  ConnectionLocalWidget::syncControls(local);
}

void ConnectionWidget::retranslateUi() {
  ConnectionLocalWidget::retranslateUi();
}

core::IConnectionSettingsBase* ConnectionWidget::createConnectionImpl(
    const core::connection_path_t& path) const {
  core::upscaledb::ConnectionSettings* conn = new core::upscaledb::ConnectionSettings(path);
  return conn;
}
}
}  // namespace gui
}  // namespace fastonosql
