// quick-lint-js finds bugs in JavaScript programs.
// Copyright (C) 2020  Matthew Glazar
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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <gtest/gtest.h>
#include <quick-lint-js/char8.h>
#include <string>

// @@@ https://github.com/microsoft/vscode-extension-samples/blob/master/lsp-sample/server/src/server.ts
namespace quick_lint_js {
namespace {
// @@@ https://microsoft.github.io/language-server-protocol/specifications/specification-current/#initialize
TEST(test_lsp_server, initialize) {
  // @@@ try different IDs
  const char8 message_content[] = u8R"({
    "jsonrpc":"2.0",
    "id": 1,
    "method": "initialize",
    "params": {
      "processId": null,
      "rootUri": null,
      "capabilities": {}
    }
  })";
  string8 message = string8(u8"content-length: ") + to_string8(std::to_string(strlen(message_content))) + u8"\r\n\r\n" + message_content;

  fake_lsp_client client;
  lsp_server server(&client);
  server.append(message);

  ASSERT_EQ(client.messages.size(), 1);

  // @@@ expected result:
  // {
  //   "id": 1,
  //   // error is not given
  //   "result": {
  //     "capabilities": {
  //       "textDocumentSync": {
  //         "change": 1 (full) or 2 (incremental)
  //       }
  //     },
  //     "serverInfo": {
  //       "name": "quick-lint-js",
  //       "version": "0.1.0"
  //     }
  //   }
  // }
}
}
}
