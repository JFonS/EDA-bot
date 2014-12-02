#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define HEADER_ACCEPT "Accept:text/html,application/xhtml+xml,application/xml"
#define HEADER_USER_AGENT "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.70 Safari/537.17"

using namespace std;

void curlpp_init(curlpp::Easy &request, ostringstream &responseStream) {
  list<string> headers;
  headers.push_back(HEADER_ACCEPT);
  headers.push_back(HEADER_USER_AGENT);
  request.setOpt(new curlpp::options::HttpHeader(headers));
  request.setOpt(new curlpp::options::FollowLocation(true));
  request.setOpt(curlpp::options::SslVerifyPeer(false));
  request.setOpt(curlpp::options::SslVerifyHost(false));

  curlpp::options::WriteStream streamWriter(&responseStream);
  request.setOpt(streamWriter);
}

int read_last_round() {
  fstream sav;
  
  
}


int main() {
  curlpp::Easy request;
  ostringstream responseStream;
  curlpp_init(request, responseStream);



  for (int i = 1; i < 14; ++i) {

    char buff[100];
    sprintf(buff, "https://www.jutge.org/competitions/AlbertAtserias:EDA_2014_2015_Q1/round/%d", i);
    string url = buff;
    request.setOpt(curlpp::options::Url(url));

    request.perform();
    string re = responseStream.str();
    size_t found = re.find("<h1>Player out: </h1>");
    if (found != string::npos) {
      size_t inici = re.find(found+1,"++++++");
      size_t fi =  re.find(found+1,"------");
      if (inici != string::n_pos and fi != string::n_pos) {
        string dead =  re.substr(inici+offset1, fi-offset2);
        cout <<  dead << " is out" <<  endl;
      } else {
        cout << "NOVA RONDA (" << i << ")" << endl;
      }
    } else {
      cout << "NOT YET (" << i << ")" << endl;
    }
    responseStream.str(string());
  }

  return 0;
}