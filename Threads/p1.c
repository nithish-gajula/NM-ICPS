#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

#include<pthread.h>

 

struct data

{

        int a;

        int b;

};

 

void *thread_fun1(void *);

void *thread_fun2(void *);

 

int main()

{

        pthread_t thread1,thread2;

        int ret;

       

        struct data DATA={255,1785};

       

        printf("a=%d b%d\n",DATA.a,DATA.b);

               

        ret=pthread_create(&thread1,NULL,thread_fun1,(void *)&DATA);//

        if(ret<0)

        {

                perror("pthread_create fail-1\n");

                exit(0);

        }

        ret=pthread_create(&thread2,NULL,thread_fun2,(void *)&DATA);//

        if(ret<0)

        {

                perror("pthread_create fail-2\n");

                exit(0);

        }

 

        ret=pthread_join(thread1,NULL);//

        if(ret<0)

        {

                perror("pthread_join fail1\n");

                exit(0);

        }

        ret=pthread_join(thread2,NULL);//

        if(ret<0)

        {

                perror("pthread_join fail2\n");

                exit(0);

        }

 

return 0;

}

 

 

void *thread_fun1(void *arg)

{      

        struct data *VALUE = (struct data *)arg;

 

        printf("mul=%d ",VALUE->a*VALUE->b);

        printf("div=%d\n",VALUE->b/VALUE->a);

 

pthread_exit(NULL);

}

void *thread_fun2(void *arg)

{

        struct data *VALUE = (struct data *)arg;

 

        printf("add=%d ",VALUE->a+VALUE->b);

        printf("sub=%d\n",VALUE->b-VALUE->a);

 

pthread_exit(NULL);

}
