// 학과 : 인공지능공학부
// 학번 : 2414320
// 이름 : 최지은
// 프로그램 파일명 : 피난소 대기열 입소 시스템 구현
// 프로그램 실제 작성일 : 2025/5/14~ 2025/5/15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 피난민 정보를 저장하는 노드 구조체
struct Node {
    char name[30];             // 피난민 이름
    struct Node* next;         // 다음 노드를 가리키는 포인터
};

// 큐의 앞과 뒤를 가리키는 포인터 초기화
struct Node* front = NULL;
struct Node* rear = NULL;




// 큐 상태 출력 함수
void printQueue() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("현재 큐 상태: (비어 있음)\n");
        return;
    }

    printf("현재 큐 상태: ");
    while (temp != NULL) {
        printf("%s", temp->name);
        if (temp->next != NULL) printf(" → "); //구조체의 링크필드가 null이 아니면 '->' 출력하고
        temp = temp->next; //한칸 전진.
    }
    printf("\n");
}

// 일반 피난민 추가 함수 (뒤에 추가)
void enqueue(char name[]) {
    struct Node* newNode;            // 새로운 노드를 가리킬 포인터 선언
    newNode = (struct Node*)malloc(sizeof(struct Node)); //node의 사이즈만큼 메모리 공간을 배정하고, struct Node 타입으로 변환해서 반환
    strcpy_s(newNode->name, sizeof(newNode->name), name); //name을 newNode->name에 복사. 
    newNode->next = NULL;

    if (rear == NULL) {
        // 큐가 비어있는 경우
        front = newNode;
        rear = newNode;
    }
    else {
        // 뒤에 연결
        rear->next = newNode;
        rear = newNode;
    }

    printQueue();
}

// VIP 피난민 추가 함수 (앞에 추가)
void enqueue_front(char name[]) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy_s(newNode->name, sizeof(newNode->name), name);
    newNode->next = front;
    front = newNode;

    // 큐가 비어 있었던 경우 rear도 설정
    if (rear == NULL) {
        rear = newNode;
    }

    printQueue();
}

// 대기열에서 피난민 퇴소 (앞에서 제거)
void dequeue() {
    if (front == NULL) {
        printf("큐가 비어 있습니다. 퇴소할 피난민이 없습니다.\n");
        return;
    }

    struct Node* temp = front;
    printf("퇴소: %s\n", temp->name); //첫노드의 이름 출력
    front = front->next; //한 칸 전진 

    // 큐가 비게 되면 rear도 NULL로
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    printQueue();
}

// 메인 함수
int main() {
    dequeue();
    enqueue("jaemin");
    enqueue("alice");
    enqueue_front("jieun");
    dequeue();
    enqueue("Tom");

    return 0;
}
