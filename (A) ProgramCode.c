//�а� : �ΰ����ɰ��к�
//�й� : 2414320
//�̸� : ������
//���α׷� ���ϸ� : [9] ī�� ������ ����
//���α׷� ���� �ۼ��� : 2025/5/30

#include <stdio.h>

#define SIZE 5  // ť ũ�� ����

// ť �ڷ��� ����
typedef struct {
    int data[SIZE];  // �����͸� ������ �迭
    int front;       // ���� ���� ����� �ε��� (���� ���)
    int rear;        // ���� ������ ����� �ε��� (�߰� ���)
} Queue;

// ť �ʱ�ȭ �Լ�
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}


// ť�� ������� Ȯ��
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// ť�� ���� á���� Ȯ��
int isFull(Queue* q) {
    return q->rear == SIZE - 1;
}

// ť�� ��Ҹ� �߰��ϴ� �Լ� (enqueue)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("ť�� ���� á���ϴ�. �� �̻� �߰��� �� �����ϴ�.\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

// ť���� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ� (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("ť�� ��� �ֽ��ϴ�. ������ �� �����ϴ�.\n");
        return -1;
    }
    q->front++;
    return q->data[q->front];
}




// ���� �Լ�
int main() {
    Queue q;
    initQueue(&q);  // ť �ʱ�ȭ

    int cards[SIZE] = { 3, 7, 2, 9, 5 };  // ī�� ��ȣ �Է� (������ 5��)

    // ī�带 ť�� ���� (enqueue)
    for (int i = 0; i < SIZE; i++) {
        enqueue(&q, cards[i]);
    }

    // ť���� ī�带 �ϳ��� ������ ��� (dequeue)
    printf("ī�� ���� ����: ");
    for (int i = 0; i < SIZE; i++) {
        int card = dequeue(&q);  // �տ������� �ϳ��� ����
        printf("%d ", card);
    }

    printf("\n");
    return 0;
}
 