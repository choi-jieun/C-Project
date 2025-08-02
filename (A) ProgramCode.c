// �а� : �ΰ����ɰ��к�
// �й� : 2414320
// �̸� : ������
// ���α׷� ���ϸ� : �ǳ��� ��⿭ �Լ� �ý��� ����
// ���α׷� ���� �ۼ��� : 2025/5/14~ 2025/5/15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ǳ��� ������ �����ϴ� ��� ����ü
struct Node {
    char name[30];             // �ǳ��� �̸�
    struct Node* next;         // ���� ��带 ����Ű�� ������
};

// ť�� �հ� �ڸ� ����Ű�� ������ �ʱ�ȭ
struct Node* front = NULL;
struct Node* rear = NULL;




// ť ���� ��� �Լ�
void printQueue() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("���� ť ����: (��� ����)\n");
        return;
    }

    printf("���� ť ����: ");
    while (temp != NULL) {
        printf("%s", temp->name);
        if (temp->next != NULL) printf(" �� "); //����ü�� ��ũ�ʵ尡 null�� �ƴϸ� '->' ����ϰ�
        temp = temp->next; //��ĭ ����.
    }
    printf("\n");
}

// �Ϲ� �ǳ��� �߰� �Լ� (�ڿ� �߰�)
void enqueue(char name[]) {
    struct Node* newNode;            // ���ο� ��带 ����ų ������ ����
    newNode = (struct Node*)malloc(sizeof(struct Node)); //node�� �����ŭ �޸� ������ �����ϰ�, struct Node Ÿ������ ��ȯ�ؼ� ��ȯ
    strcpy_s(newNode->name, sizeof(newNode->name), name); //name�� newNode->name�� ����. 
    newNode->next = NULL;

    if (rear == NULL) {
        // ť�� ����ִ� ���
        front = newNode;
        rear = newNode;
    }
    else {
        // �ڿ� ����
        rear->next = newNode;
        rear = newNode;
    }

    printQueue();
}

// VIP �ǳ��� �߰� �Լ� (�տ� �߰�)
void enqueue_front(char name[]) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy_s(newNode->name, sizeof(newNode->name), name);
    newNode->next = front;
    front = newNode;

    // ť�� ��� �־��� ��� rear�� ����
    if (rear == NULL) {
        rear = newNode;
    }

    printQueue();
}

// ��⿭���� �ǳ��� ��� (�տ��� ����)
void dequeue() {
    if (front == NULL) {
        printf("ť�� ��� �ֽ��ϴ�. ����� �ǳ����� �����ϴ�.\n");
        return;
    }

    struct Node* temp = front;
    printf("���: %s\n", temp->name); //ù����� �̸� ���
    front = front->next; //�� ĭ ���� 

    // ť�� ��� �Ǹ� rear�� NULL��
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    printQueue();
}

// ���� �Լ�
int main() {
    dequeue();
    enqueue("jaemin");
    enqueue("alice");
    enqueue_front("jieun");
    dequeue();
    enqueue("Tom");

    return 0;
}
