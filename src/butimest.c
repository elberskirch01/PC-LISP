

/*
 | PC-LISP (C) 1984-1989 Peter J.Ashwood-Smith
 */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "lisp.h"

/*************************************************************************
 ** (time-string [fixnum]) Will return a string representing the time   **
 ** fixnum seconds after creation. If fixnum is not provided then the   **
 ** current time string is returned.                                    **
 *************************************************************************/
struct conscell * butimestring(struct conscell *form)
{
       lifix64_t fix; int len;
       time_t t;
       char *s;
       if (form != NULL) {
          if ((form->cdrp != NULL)||(!GetFix64(form->carp,&fix))) goto er;
          t = (time_t) fix;
       } else {
          t = time(NULL);
       }
       s = ctime(&t);
       if (s == NULL) goto er;
       len = strlen(s);
       if (len <= 0) goto er;
       len -= 1;
       if (s[len] == '\n') s[len] = '\0';    /* ctime may put a new line, get rid of it */
       return(LIST(insertstring(s)));
er:    ierror("time-string");  /*  doesn't return  */
       return NULL;   /*  keep compiler happy  */
 }
