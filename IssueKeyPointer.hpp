#pragma once
#include <nlohmann/json.hpp>
#include <cpp-httplib/httplib.h>

namespace ohtoai {
	namespace github {
		using namespace nlohmann::literals::json_literals;
		namespace webhook
		{
			namespace issue_request
			{
				static const auto Action = "/action"_json_pointer;

				static const auto IssueUrl = "/issue/url"_json_pointer;
				static const auto IssueHtmlUrl = "/issue/html_url"_json_pointer;
				static const auto IssueId = "/issue/id"_json_pointer;
				static const auto IssueBody = "/issue/body"_json_pointer;
				static const auto IssueCreatedAt = "/issue/created_at"_json_pointer;
				static const auto IssueUpdatedAt = "/issue/updated_at"_json_pointer;

				static const auto IssueNumber = "/issue/number"_json_pointer;
				static const auto IssueTitle = "/issue/title"_json_pointer;
				static const auto IssueState = "/issue/state"_json_pointer;
				static const auto IssueComments = "/issue/comments"_json_pointer;

				static const auto IssueUserLogin = "/issue/user/login"_json_pointer;
				static const auto IssueUserId = "/issue/user/id"_json_pointer;
				static const auto IssueUserUrl = "/issue/user/url"_json_pointer;
				static const auto IssueUserHtmlUrl = "/issue/user/html_url"_json_pointer;
				static const auto IssueUserAvatar = "/issue/user/avatar_url"_json_pointer;

				static const auto IssueLabels = "/issue/user/labels"_json_pointer;
				
				static const auto CommentUrl = "/comment/url"_json_pointer;
				static const auto CommentHtmlUrl = "/comment/html_url"_json_pointer;
				static const auto CommentId = "/comment/id"_json_pointer;
				static const auto CommentBody = "/comment/body"_json_pointer;
				static const auto CommentCreatedAt = "/comment/created_at"_json_pointer;
				static const auto CommentUpdatedAt = "/comment/updated_at"_json_pointer;

				static const auto CommentUserLogin = "/comment/user/login"_json_pointer;
				static const auto CommentUserId = "/comment/user/id"_json_pointer;
				static const auto CommentUserUrl = "/comment/user/url"_json_pointer;
				static const auto CommentUserHtmlUrl = "/comment/user/html_url"_json_pointer;
				static const auto CommentUserAvatar = "/comment/user/avatar_url"_json_pointer;
				
				static const auto RepositoryName = "/repository/name"_json_pointer;
				static const auto RepositoryId = "/repository/id"_json_pointer;
				static const auto RepositoryUrl = "/repository/url"_json_pointer;
				static const auto RepositoryHtmlUrl = "/repository/html_url"_json_pointer;
				static const auto RepositoryFullName = "/repository/full_name"_json_pointer;
				static const auto RepositoryPrivate = "/repository/private"_json_pointer;
				static const auto RepositoryDefaultBranch = "/repository/default_branch"_json_pointer;

				static const auto RepositoryOwnerUserLogin = "/repository/owner/login"_json_pointer;
				static const auto RepositoryOwnerUserId = "/repository/owner/id"_json_pointer;
				static const auto RepositoryOwnerUserUrl = "/repository/owner/url"_json_pointer;
				static const auto RepositoryOwnerUserHtmlUrl = "/repository/owner/html_url"_json_pointer;
				static const auto RepositoryOwnerUserAvatar = "/repository/owner/avatar_url"_json_pointer;
			}
		}
	
		namespace api
		{
			std::string get_issue_comments(const std::string& owner, const std::string& repo, int issue_number)
			{
				httplib::Client cli("https://api.github.com");
				cli.set_follow_location(true);
				auto ret = cli.Get(("/repos/" + owner + "/" + repo + "/issues/" + std::to_string(issue_number) + "/comments").c_str());
				if (ret)
				{
					return ret->body;
				}
				return "";
			}
			
			std::string post_issue_comment(const std::string& owner, const std::string& repo, int issue_number, const std::string& token, const std::string& body)
			{
				httplib::Client cli("https://api.github.com");
				cli.set_follow_location(true);
				auto ret = cli.Post(("/repos/" + owner + "/" + repo + "/issues/" + std::to_string(issue_number) + "/comments").c_str(), { {"Authorization", "token " + token} }, R"({"body": ")" + body + R"("})", "application/json");
				if (ret)
				{
					return ret->body;
				}
				return "";
			}

			std::string get_issue(const std::string& owner, const std::string& repo, int issue_number)
			{
				httplib::Client cli("https://api.github.com");
				cli.set_follow_location(true);
				auto ret = cli.Get(("/repos/" + owner + "/" + repo + "/issues/" + std::to_string(issue_number)).c_str());
				if (ret)
				{
					return ret->body;
				}
				return "";
			}
		}
	}
}
