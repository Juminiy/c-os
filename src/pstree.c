#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <malloc.h>
#include <dirent.h>
#include <error.h>
#include <stdlib.h>


#define DIR_PATH "/proc"
#define FILE_STATUS "status"
#define PROC_ATTRIBUTE_NAME "Name"
#define PROC_ATTRIBUTE_PPID "PPid"
#define BOOL_TRUE  1
#define BOOL_FALSE 0
#define MAX_PROC_LEN 30
#define MAX_DIR_LEN 50
#define SYS_PROC_CNT 100000
#define SYS_PROC_CHILD_CNT 25
// 2023.03.14 <chisato-x at qq dot com> 
/* task 
1. /proc/[PID] 
  1.1 FILE i/o 
  FILE *filePtr = fopen("tfile.txt", "a+");
  if(filePtr) {
    char ch, index = 0;
    char *istr = (char *)(malloc(15));
    fgets(istr, 15, filePtr);
    printf("origin %d bytes: %s\n", strlen(istr), istr);
    while((ch=getchar()) != '\n' && index < 15) {
      istr[index++] = ch;
    }
    fputs((index) ? istr : "", filePtr);
    fclose(filePtr);
  }
  1.2 pid ppid 
  pid_t pid_cur = getpid(), ppid_cur = getppid();
  printf("%d, %d\n", pid_cur, ppid_cur);
  1.3 vist folder and file recursive 
2. process itself, processes themselves
  2.1 ok success
3. build tree printf
*/
void init_proc_status(int, int, const char *);
void proc_children_realloc(int);
void proc_children_add(int, int);
void debug_psa(int);

typedef struct proc_status {
  int pid, ppid;
  char *name;
  int *children, childcnt, maxcnt;
} ps;

ps psa[SYS_PROC_CNT];

void init_proc_status(int _pid, int _ppid, const char *_name){
  psa[_pid].pid = _pid;
  psa[_pid].ppid = _ppid;
  psa[_pid].name = (char *)(malloc(MAX_PROC_LEN));
  strcpy(psa[_pid].name, _name);
  psa[_pid].childcnt = 0;
  psa[_pid].maxcnt = SYS_PROC_CHILD_CNT;
  psa[_pid].children = (int *)(malloc(SYS_PROC_CHILD_CNT * sizeof(int)));
}

void proc_children_realloc(int _pid){

  int sz =  psa[_pid].maxcnt;
  int *newChildrenPtr = (int *)(malloc((sz << 1) * sizeof(int)));
  assert(newChildrenPtr);
  for(int i = 0; i < sz; i ++){
    newChildrenPtr[i] = psa[_pid].children[i];
  }
  free(psa[_pid].children);
  psa[_pid].children = newChildrenPtr;
  psa[_pid].maxcnt = sz << 1;

}


// realloc bug error
// realloc bug solved  
void proc_children_add(int _pid, int _cpid){
  if(psa[_pid].childcnt >= psa[_pid].maxcnt){
    proc_children_realloc(_pid);
  }
  psa[_pid].children[psa[_pid].childcnt++] = _cpid;
}

void proc_children_add_test(){
  init_proc_status(1, 0, "sss");
  debug_psa(1);
  proc_children_add(1, 1);
  proc_children_add(1, 2);
  proc_children_add(1, 3);
  proc_children_add(1, 4);
  proc_children_add(1, 5);
  proc_children_add(1, 6);
  proc_children_add(1, 7);
  proc_children_add(1, 8);
  proc_children_add(1, 9);
  proc_children_add(1, 10);
  proc_children_add(1, 11);
  proc_children_add(1, 12);
  proc_children_add(1, 13);
  proc_children_add(1, 14);
  proc_children_add(1, 15);
  proc_children_add(1, 16);
  proc_children_add(1, 17);
  proc_children_add(1, 18);
  proc_children_add(1, 19);
  proc_children_add(1, 20);
  proc_children_add(1, 21);
  proc_children_add(1, 22);
  proc_children_add(1, 23);
  proc_children_add(1, 24);
  proc_children_add(1, 25);
  proc_children_add(1, 26);
  proc_children_add(1, 27);
  proc_children_add(1, 28);
  proc_children_add(1, 29);
  proc_children_add(1, 30);
  proc_children_add(1, 31);
  proc_children_add(1, 32);
  debug_psa(1);
}


void error_print(const char *error_line){
  printf("%s ", error_line);
}
void error_println(const char *error_line){
  printf("%s\n", error_line);
}

void debug_print_int(int debug_num){
  printf("%d ", debug_num);
}
void debug_println_int(int debug_num){
  printf("%d\n", debug_num);
}

void debug_print(const char *debug_line){
  printf("%s ", debug_line);
}
void debug_println(const char *debug_line){
  printf("%s\n", debug_line);
}

void debug_psa(int _pid){
  printf("pid: %d, pname: %s, ppid: %d, pchild: [", _pid, psa[_pid].name, psa[_pid].ppid);
  int pcl = psa[_pid].childcnt;
  for(int i = 0; i < pcl-1; i ++){
    printf("%d, ", psa[_pid].children[i]);
  }
  printf("%d]\n", psa[_pid].children[pcl-1]);
}

int str_is_num(const char *str){
  assert(str);
  int len = strlen(str);
  for(int i = 0; i < len; i ++){
    if(str[i]<'0' || str[i]>'9')
      return BOOL_FALSE;
  }
  return BOOL_TRUE;
}

int str_to_int(const char *value){
  int num_t = 0, str_l = strlen(value), str_i = 0;
  while(str_i < str_l){
    num_t = (num_t << 3) + (num_t << 1) + (value[str_i] - '0');
    str_i ++;
  }
  return num_t;
}

int str_cmp(const char *s1, const char *s2){
  assert(s1), assert(s2);
  int l1 = strlen(s1), l2 = strlen(s2);
  if(l1 != l2)
    return BOOL_FALSE;
  int i1 = 0, i2 = 0;
  while(i1 < l1 && i2 < l2){
    if(s1[i1] != s2[i2])
      return BOOL_FALSE;
    i1 ++, i2 ++;
  }
  return BOOL_TRUE;
}


// test passed
// date : 2023.03.15 
// email: chisato-x at qq dot com 
// printf("%s\n%s\n", str_fmt_num("12uiswe\t sd2222swwews\0"), str_fmt_nst("sds   \t \t sdsd\0 "));
int select_num_fun(char ch){
  return (ch >= '0' && ch <= '9') ? BOOL_TRUE : BOOL_FALSE; 
}
int select_nst_fun(char ch){
  return (ch == '\t' || ch == ' ') ? BOOL_FALSE : BOOL_TRUE;
}

char *str_fmt(const char *str, int (*select_fun_ptr) (char)){
  char *ss = (char *)(malloc(MAX_PROC_LEN));
  int str_i = 0, str_l = strlen(str), ssi = 0;

  while(str_i < str_l){
    if(select_fun_ptr(str[str_i])) 
      ss[ssi++] = str[str_i];
    str_i ++;
  }

  ss[ssi] = '\0';
  return ss;
}


char *str_fmt_num(const char *str){
  return str_fmt(str, select_num_fun);
}

char *str_fmt_nst(const char *str){
  return str_fmt(str, select_nst_fun);
}

char *str_arr_copy(char *dest,const char *src_arr[5], const int len){
  assert(dest), assert(len);
  for(int i = 0; i < len; i ++){
    dest = strcat(dest, src_arr[i]);
  }
  dest = strcat(dest, "\0");
  return dest;
}

char *read_proc_attribute(FILE *file_ptr, const char *attribute_name){
  int ch, after_tdot = BOOL_FALSE, attri_match = BOOL_FALSE;
  char *key = (char *)(malloc(MAX_PROC_LEN));
  char *val = (char *)(malloc(MAX_PROC_LEN));
  int kindex = 0, vindex = 0;

  while((ch = fgetc(file_ptr)) && ch != EOF) 
  {
    switch (ch)
    {
    case '\n':{
        if(attri_match)
          goto ref1;
        after_tdot = BOOL_FALSE;
        kindex = 0;
      }
      break;
    case ':':{
        after_tdot = BOOL_TRUE;
        key[kindex] = '\0';
        if(str_cmp(attribute_name, key))
          attri_match = BOOL_TRUE;
      }
      break;
    default:{
        if(after_tdot && attri_match)
          val[vindex++] = (char)ch;
        if(!after_tdot)
          key[kindex++] = (char)ch;
      }
      break;
    }
  }
ref1:
  val[vindex] = '\0';
  return val;
}

char *read_proc_name(FILE *file_ptr){
  char *str_name = read_proc_attribute(file_ptr, PROC_ATTRIBUTE_NAME); 
  str_name = str_fmt_nst(str_name);
  return str_name;
}

int read_proc_ppid(FILE *file_ptr){
  char *ppid = read_proc_attribute(file_ptr, PROC_ATTRIBUTE_PPID);
  ppid = str_fmt_num(ppid);
  assert(str_is_num(ppid));
  return str_to_int(ppid);
}

void read_proc_file(){
  DIR *dir = opendir(DIR_PATH);
  struct dirent *proc_dirent;
  if(dir){
    while((proc_dirent = readdir(dir)) != NULL){
      char *str_pid = proc_dirent->d_name;
      if(!str_is_num(str_pid)) 
        continue;
      const char *slice[5] = {DIR_PATH, "/", str_pid, "/", FILE_STATUS};
      char *ppath = (char *)(malloc(MAX_DIR_LEN));
      ppath = str_arr_copy(ppath, slice, 5);
      FILE *filePtr = fopen(ppath, "r");
      if(filePtr){
        int pid = str_to_int(str_fmt_num(str_pid));
        char *pname = read_proc_name(filePtr);
        int ppid = read_proc_ppid(filePtr);
        debug_print_int(pid), debug_print(pname), debug_println_int(ppid);
        init_proc_status(pid, ppid, pname);
        fclose(filePtr);
      } else {
        error_println("file status does not exist");
      }
    }
  } else{
    error_println("directory /proc does not exist");
  } 
}


int main(int argc, char *argv[]) {

  for (int i = 0; i < argc; i++) {
    assert(argv[i]);
    printf("argv[%d] = %s\n", i, argv[i]);
  }
  assert(!argv[argc]);

  read_proc_file();

  // proc_children_add_test();

  return 0;
}
