// mtfind2(1) -- Multi-thread find utility: the sequel that nobody needs
// Copyright (c) 2021 Ángel Pérez <angel.perez7@alu.uclm.es>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#pragma once

#include <chrono>
#include <string>

#include <Shared/NonCopyable.h>

namespace mtfind2 {
/**
 * Search requests simply contain the search term (query) and a timestamp for
 * calculating response time. As they are short-lived and intended to be
 * single-instance, no copy semantics are allowed on search request objects.
 */
struct SearchRequest final : NonCopyable {
    explicit SearchRequest(std::string query)
        : m_query(std::move(query))
        , m_timestamp(std::chrono::steady_clock::now())
    {
    }

    const std::string &query() const { return m_query; }
    const std::chrono::time_point<std::chrono::steady_clock> &timestamp() const { return m_timestamp; }

private:
    const std::string m_query;
    const std::chrono::time_point<std::chrono::steady_clock> m_timestamp;
};
}