/*#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>

#define HEADER_ACCEPT "Accept:text/html,application/xhtml+xml,application/xml"
#define HEADER_USER_AGENT "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.70 Safari/537.17"
#define SAVE_FILE "eda-bot-save.txt"
#define NO_ROUND "AJAHBDBJbgajFbIfFrDdHkBbcSdRWDghOpJb"
using namespace std;

/*curlpp::Easy request;
ostringstream responseStream;

void curlpp_init() {
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
  ifstream isav(SAVE_FILE);
  int n;
  if (isav.good()) {
    isav >>  n;
  }  else {
    n = 1;
    while (get_round(n) !=  NO_PLAYER) ++n;
    ofstream osav;
    osav.open(SAVE_FILE);
    osav <<  n;
    osav.close();
  }
  isav.close();
  return n;
}

string get_round(int i) {
  string ret =  NO_ROUND;
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
        ret =  re.substr(inici+offset1, fi-offset2);
      } else {
        ret =  "";
      }
    }
    responseStream.str(string());
    return ret;
}*/


int main() {
  //curlpp_init();
  int last_round = 7;//  read_last_round();
  
  while(true) {
    string res = NO_ROUND;// get_round(last_round + 1);
    if (res !=  NO_ROUND) {
      //send_twit(res);
      ++last_round;
    } else {
      cout <<  "lolo";
      usleep(1000000);
    }
  }

  return 0;
}