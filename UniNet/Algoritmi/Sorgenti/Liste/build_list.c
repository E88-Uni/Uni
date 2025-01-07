#include <stdio.h>
#include <stdlib.h>
typedef struct lista{
    int val;
    struct lista *next;
} *pl;

pl newl(int n) {
    pl p = malloc(sizeof(struct lista));
    p->next = NULL;
    p->val = n;
    return p;
}
pl add_tail(int n, pl p) {
    if(p->next == NULL){
        pl newp = malloc(sizeof(struct lista));
        p->next = newp;
        newp->next = NULL;
        newp->val = n;
        return newp;
    }else{
        return add_tail(n, p->next);
    }
    
}

pl add_head(int n, pl p) {
    pl newp = malloc(sizeof(struct lista));
    newp->next = p;
    newp->val = n;
    return newp;
}

pl del_tail(pl p) {
    if(p->next != NULL && p->next->next == NULL){
        free(p->next);
        p->next = NULL;
        return p;
    }else if(p->next == NULL){
        return NULL;
    }else{
        return del_tail(p->next);
    }
    
}

pl del_head(pl p) {
    pl pp = p->next;
    free(p);
    return pp;
}

void l_print(pl p) {
     printf("%d ", p->val);
    if(p->next != NULL){
        l_print(p->next);
    }
}
int main() {
    int flag, i=0;
    pl pp= newl(10);
    for(; i < 10; i++){
        add_tail(i, pp);
        pp = add_head(i, pp);
    }
    l_print(pp);
    printf("\n");
    for(i=0; i < 10; i++){
        del_tail(pp);
        pp = del_head(pp);
    }
    l_print(pp);
    scanf("%d", &flag); 
    return 0;
}