#include"head.h"
#define MAX 128
struct mq_attr attrQ;
 int main(int argc, char const *argv[]) {
  mqd_t fdQue;
  attrQ.mq_flags=0;
  attrQ.mq_maxmsg=4;
  attrQ.mq_msgsize=MAX;
  attrQ.mq_curmsgs=0;
  fdQue = mq_open("/mQue",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR,&attrQ);
  mq_send(fdQue,"Hello\n",6,0);
  mq_close(fdQue);
  return 0;
}
