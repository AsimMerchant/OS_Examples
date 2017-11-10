#include"head.h"
#define MAX 128
struct mq_attr attrQ;
char buffer[MAX];
 int main(int argc, char const *argv[]) {
  mqd_t fdQue;
  attrQ.mq_flags=0;
  attrQ.mq_maxmsg=4;
  attrQ.mq_msgsize=MAX;
  attrQ.mq_curmsgs=0;
  fdQue = mq_open("/mQue",O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR,&attrQ);
  mq_receive(fdQue,buffer,MAX,0);
  printf("%s\n",buffer );
  mq_close(fdQue);
  return 0;
}
