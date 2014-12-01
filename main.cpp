#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <iostream>
#include <string>
#include <sstream>

#define HEADER_ACCEPT "Accept:text/html,application/xhtml+xml,application/xml"
#define HEADER_USER_AGENT "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.70 Safari/537.17"

using namespace std;

int main() {
  curlpp::Easy request;

  list<string> headers;
  headers.push_back(HEADER_ACCEPT);
  headers.push_back(HEADER_USER_AGENT);
  request.setOpt(new curlpp::options::HttpHeader(headers));
  request.setOpt(new curlpp::options::FollowLocation(true));
  request.setOpt(curlpp::options::SslVerifyPeer(false));
  request.setOpt(curlpp::options::SslVerifyHost(false));

  ostringstream responseStream;
  curlpp::options::WriteStream streamWriter(&responseStream);
  request.setOpt(streamWriter);

  for (int i = 1; i < 14; ++i) {

    char buff[100];
    sprintf(buff, "https://www.jutge.org/competitions/AlbertAtserias:EDA_2014_2015_Q1/round/%d", i);
    string url = buff;
    request.setOpt(curlpp::options::Url(url));

    request.perform();
    string re = responseStream.str();
    size_t found = re.find("<h1>Player out: </h1>");
    if (found != string::npos) {
      cout << "NOVA RONDA (" << i << ")" << endl;
    } else {
      cout << "NOT YET (" << i << ")" << endl;
    }
    responseStream.str(string());
  }

  return 0;
}
