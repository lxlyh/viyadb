/*
 * Copyright (c) 2017-present ViyaDB Group
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef VIYA_SERVER_HTTP_SERVICE_H_
#define VIYA_SERVER_HTTP_SERVICE_H_

#include "util/config.h"
#include <server_http.hpp>

namespace viya {
namespace db {
class Database;
}
} // namespace viya

namespace viya {
namespace server {
namespace http {

namespace util = viya::util;
namespace db = viya::db;

typedef SimpleWeb::Server<SimpleWeb::HTTP> HttpServer;
typedef std::shared_ptr<HttpServer::Request> RequestPtr;
typedef std::shared_ptr<HttpServer::Response> ResponsePtr;

class Service {
public:
  Service(const util::Config &config, db::Database &database);

  void Start();

private:
  void SendError(ResponsePtr response, const std::string &error);

private:
  db::Database &database_;
  HttpServer server_;
};
} // namespace http
} // namespace server
} // namespace viya

#endif // VIYA_SERVER_HTTP_SERVICE_H_
