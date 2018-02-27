/* 
题目描述：
    输入一个链表，反转链表后，输出链表的所有元素。
*/

ListNode* ReverseList(ListNode* head) {
    //当前节点是head，pre为当前节点的前一节点，next为当前节点的下一节点
    //需要pre和next的目的是让当前节点从pre->head->next1->next2变成pre<-head next1->next
    //即pre让节点可以反转所指方向，但反转之后如果不用next节点保存next1节点的话，此单链表就此断开了
    //所以需要用到pre和next两个节点
    //1->2->3->4->5
    //1<-2<-3 4->5
    ListNode *pre = NULL,*next = NULL;
    if(head == NULL) return head;
    while(head != NULL){
        //做循环，如果当前节点不为空的话，始终执行此循环，此循环的目的就是让当前节点从指向next到指向pre
        //如此就可以做到反转链表的效果
        //先用next保存head的下一个节点的信息，保证单链表不会因为失去head节点的原next节点而就此断裂
        next = head->next;
        //保存完next，就可以让head从指向next变成指向pre了，代码如下
        head->next = pre;
        //head指向pre后，就继续依次反转下一个节点
        pre = head;
        head = next;
        //让pre，head，next依次向后移动一个节点，继续下一次的指针反转
    }
    //如果head为null的时候，pre就为最后一个节点了，但是链表已经反转完毕，pre就是反转后链表的第一个节点
    //直接输出pre就是我们想要得到的反转后的链表
    return pre;
}

/*
测试地址：https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking 
*/