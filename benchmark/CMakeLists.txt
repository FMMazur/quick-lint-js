# quick-lint-js finds bugs in JavaScript programs.
# Copyright (C) 2020  Matthew Glazar
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.10)
include(QuickLintJSTarget)

function (quick_lint_js_add_benchmark_executable TARGET_NAME)
  set(SOURCES "${ARGN}")
  quick_lint_js_add_executable("${TARGET_NAME}" ${SOURCES})
  target_link_libraries(
    "${TARGET_NAME}"
    PRIVATE
    benchmark::benchmark
    benchmark::benchmark_main
    quick-lint-js-lib
  )
endfunction ()

quick_lint_js_add_benchmark_executable(
  quick-lint-js-benchmark-lex
  benchmark-lex.cpp
)
quick_lint_js_add_benchmark_executable(
  quick-lint-js-benchmark-lint
  benchmark-lint.cpp
)
quick_lint_js_add_benchmark_executable(
  quick-lint-js-benchmark-location
  benchmark-location.cpp
)
quick_lint_js_add_benchmark_executable(
  quick-lint-js-benchmark-parse
  benchmark-parse.cpp
)
quick_lint_js_add_benchmark_executable(
  quick-lint-js-benchmark-translation
  benchmark-translation.cpp
)
