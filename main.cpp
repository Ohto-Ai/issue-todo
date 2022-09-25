#include "IssuePannel.h"
#include <QtWidgets/QApplication>
#include "IssueKeyPointer.hpp"
#include <cpp-httplib/httplib.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	
    httplib::Server server;
    server.bind_to_port("0.0.0.0", 8003);
	
    server.Post("/api/github/hook/issue", [&](const httplib::Request req, httplib::Response& res)
        {
            using namespace ohtoai::github::webhook;
            using std::string;
            auto j = nlohmann::json::parse(req.body);
            string action = j[issue_request::Action];
            string repo = j[issue_request::RepositoryName];
            string owner = j[issue_request::RepositoryOwnerUserLogin];
            string comment_body = j[issue_request::CommentBody];
            string comment_user = j[issue_request::CommentUserLogin];

            nlohmann::json ret;
            ret["action"] = action;
			ret["repo"] = repo;
			ret["owner"] = owner;
            ret["comment_body"] = comment_body;
            ret["comment_user"] = comment_user;
			
			res.set_content(ret.dump(4), "application/json");
        });

	server.Get(R"(/api/github/([^/]+)/([^/]+)/issues/(\d+)/comments/post)", [&](const httplib::Request req, httplib::Response& res)
        {
            std::string owner = req.matches[1];
            std::string repo = req.matches[2];
            int issue_number = stoi(req.matches[3]);
            std::string body = req.get_param_value("body");
            std::string token = req.get_param_value("token");

            auto ret = ohtoai::github::api::post_issue_comment(owner, repo
                , issue_number, token, body);
            res.set_content(nlohmann::json::parse(ret).dump(4), "application/json");
        });

    server.listen_after_bind();

    IssuePannel w;
    w.show();
    return a.exec();
}
