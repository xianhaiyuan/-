/* 
��Ŀ����
����һ��������ת�����������������Ԫ�ء�
*/

ListNode* ReverseList(ListNode* head) {
	//��ǰ�ڵ���head��preΪ��ǰ�ڵ��ǰһ�ڵ㣬nextΪ��ǰ�ڵ����һ�ڵ�
	//��Ҫpre��next��Ŀ�����õ�ǰ�ڵ��pre->head->next1->next2���pre<-head next1->next
	//��pre�ýڵ���Է�ת��ָ���򣬵���ת֮���������next�ڵ㱣��next1�ڵ�Ļ����˵�����ʹ˶Ͽ���
    //������Ҫ�õ�pre��next�����ڵ�
    //1->2->3->4->5
    //1<-2<-3 4->5
    ListNode *pre = NULL,*next = NULL;
    if(head == NULL) return head;
    while(head != NULL){
    	//��ѭ���������ǰ�ڵ㲻Ϊ�յĻ���ʼ��ִ�д�ѭ������ѭ����Ŀ�ľ����õ�ǰ�ڵ��ָ��next��ָ��pre
        //��˾Ϳ���������ת�����Ч��
        //����next����head����һ���ڵ����Ϣ����֤����������Ϊʧȥhead�ڵ��ԭnext�ڵ���ʹ˶���
        next = head->next;
        //������next���Ϳ�����head��ָ��next���ָ��pre�ˣ���������
        head->next = pre;
        //headָ��pre�󣬾ͼ������η�ת��һ���ڵ�
        //��pre��head��next��������ƶ�һ���ڵ㣬������һ�ε�ָ�뷴ת
        pre = head;
        head = next;
    }
    //���headΪnull��ʱ��pre��Ϊ���һ���ڵ��ˣ����������Ѿ���ת��ϣ�pre���Ƿ�ת������ĵ�һ���ڵ�
    //ֱ�����pre����������Ҫ�õ��ķ�ת�������
    return pre;
}

/*
���Ե�ַ��https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking 
*/
