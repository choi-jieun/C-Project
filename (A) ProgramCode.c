// �а� : �ΰ����ɰ��к�
// �й� : 2414320
// �̸� : ������
// ���α׷� ���ϸ� : [3]���� ����Ʈ ���� �˻� (����, �˻�)
// ���α׷� ���� �ۼ��� : 2025/5/20


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TOTAL_NODES 31
#define SEARCH_COUNT 10

// ���� ����Ʈ�� ��� ����ü ����
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// �� ��带 ����� �Լ�
Node* createNode(int data) {
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node)); //node����ü��ŭ �޸𸮸� �Ҵ�ް� ��带 ����Ű�� �����ͷ� �� ��ȯ.
    newNode->data = data; 
    newNode->next = NULL;
    return newNode;
}

// ����Ʈ ���� �� ��带 �߰��ϴ� �Լ� 
void appendNode(Node** head, int data) {
    // �� ��带 ����� �� ����
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // ����Ʈ�� ��� �ִٸ� �� ��带 head�� ����
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        // ����Ʈ�� ������ ��带 ã�� ������ �̵�
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // ������ ����� next�� �� ��带 ����Ű�� ��
        temp->next = newNode;
    }
}

// ���� ���� (Selection Sort) �˰��� ����
void selectionSort(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* minNode = current;
        Node* nextNode = current->next;

        while (nextNode != NULL) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        // �� ��ȯ
        int temp = current->data;
        current->data = minNode->data;
        minNode->data = temp;

        current = current->next;
    }
}

// ���� ����Ʈ�� �迭�� �ٲٴ� �Լ� (���� Ž���� ����)
void listToArray(Node* head, int arr[], int* size) {
    int index = 0;
    while (head != NULL) {
        arr[index++] = head->data;
        head = head->next;
    }
    *size = index;
}

// �迭���� ���� Ž�� ����
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;  // ã���� �� �迭 �ε��� ��ȯ
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // �� ã���� ��
}

// ���� ����Ʈ ��ü ���
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// ���� �Լ�
int main() {
    int inputData[TOTAL_NODES] = {
        66, 2, 67, 69, 8, 11, 43, 49, 5, 6,
        70, 71, 73, 75, 48, 12, 14, 7, 15, 24,
        26, 42, 51, 55, 56, 59, 1, 3, 80, 96, 99
    };

    int searchKeys[SEARCH_COUNT] = { 3, 97, 96, 111, 15, 9, 66, 120, 99, 59 };

    Node* head = NULL;

    // 1. ���� ����Ʈ ����
    for (int i = 0; i < TOTAL_NODES; i++) {
        appendNode(&head, inputData[i]);
    }

    // 2. ���� ���� ����
    selectionSort(head);

    // 3. ���ĵ� ����Ʈ ���
    printf("���ĵ� ����Ʈ:\n");
    printList(head);

    // 4. ����Ʈ�� �迭�� ��ȯ
    int sortedArr[TOTAL_NODES];
    int size = 0;
    listToArray(head, sortedArr, &size);

    // 5. ���� Ž�� ���� �� ���
    printf("\n�˻� ���:\n");
    for (int i = 0; i < SEARCH_COUNT; i++) {
        int key = searchKeys[i];
        int index = binarySearch(sortedArr, size, key);
        printf("(%d) %d �� ", i + 1, key);
        if (index != -1) {
            printf("True, ��ġ: %d��° ���\n", index + 1);  // 1������ ����
        }
        else {
            printf("False, No Result in List\n");
        }
    }

    return 0;
}