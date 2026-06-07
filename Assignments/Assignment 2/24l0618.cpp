#include <iostream>
#include <fstream>
using namespace std;

class queueNode
{
public:
    float value;
    queueNode* nextQueueNode;

    queueNode(int val)
    {
        value = val;
        nextQueueNode = nullptr;
    }
};

class queue
{
public:
    queueNode* front;
    queueNode* rear;

    queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int val)
    {
        queueNode* n1 = new queueNode(val);

        if (front == nullptr && rear == nullptr)
        {
            front = n1;
            rear = n1;
            return;
        }

        rear->nextQueueNode = n1;
        rear = n1;
    }

    bool isEmpty()
    {
        return front == nullptr && rear == nullptr;
    }

    void Print()
    {
        queueNode* temp = front;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->nextQueueNode;
        }
        cout << endl;
    }
};

class stackNode
{
public:
    queue* queueHead;
    stackNode* nextStackNode;

    stackNode(queue* q)
    {
        queueHead = q;
        nextStackNode = nullptr;
    }
};

class stack
{
public:
    stackNode* stackHead;
    int row, col;

    stack()
    {
        stackHead = nullptr;
        row = col = 0;
    }

    void pushBack(queue* q)
    {
        stackNode* s1 = new stackNode(q);

        if (stackHead == nullptr)
        {
            stackHead = s1;
            return;
        }

        stackNode* temp = stackHead;
        while (temp->nextStackNode != nullptr)
        {
            temp = temp->nextStackNode;
        }
        temp->nextStackNode = s1;
    }

    bool isEmpty()
    {
        return stackHead == nullptr;
    }

    void Display()
    {
        stackNode* temp = stackHead;
        while (temp != nullptr)
        {
            temp->queueHead->Print();
            temp = temp->nextStackNode;
        }
    }
};

class Matrix
{
private:
    stack* m;

public:
    Matrix()
    {
        m = new stack();
        m->row = m->col = 0;
    }

    void InputRows(ifstream& mat, int rows, int cols)
    {
        if (rows == 0)
            return;

        queue* q = new queue();
        InputColumns(mat, cols, q);
        m->pushBack(q);
        InputRows(mat, rows - 1, cols);
    }

    void InputColumns(ifstream& mat, int cols, queue* q)
    {
        if (cols == 0)
            return;

        int val;
        mat >> val;
        q->enqueue(val);
        InputColumns(mat, cols - 1, q);
    }

    void MatrixInput(const char* name)
    {
        ifstream mat(name);
        if (!mat.is_open())
        {
            cout << "Error in opening file " << name << endl;
            return;
        }

        int rows, cols;
        mat >> rows >> cols;
        m->row = rows;
        m->col = cols;

        if (rows <= 0 || cols <= 0)
        {
            cout << "Invalid input " << name << endl;
            mat.close();
            return;
        }

        InputRows(mat, rows, cols);
        mat.close();
    }

    void display()
    {
        m->Display();
    }

    void AddQueueNodes(queueNode* q1, queueNode* q2,queue* result)
    {
        if (q1==nullptr && q2==nullptr)
        {
            return;
        }

        int total = 0;

        if (q1!=nullptr && q2 != nullptr)
        {
            total = q2->value + q1->value;
        }

        result->enqueue(total);

        queueNode* next1 = q1;
        queueNode* next2 = q2;

        if (q1!=nullptr && q2!=nullptr)
        {
            next1 = q1->nextQueueNode;
            next2 = q2->nextQueueNode;
        }

        AddQueueNodes(next1, next2, result);
    }

    void MoveStacks(stackNode* s1, stackNode* s2, stack* result)
    {
        if (s1==nullptr && s2==nullptr)
        {
            return;
        }

        queue* newRow = new queue();

        queueNode* q1 = nullptr;
        queueNode* q2 = nullptr;

        if (s1!=nullptr && s2 != nullptr)
        {
           q1 = s1->queueHead->front;
           q2 = s2->queueHead->front;
        }

        AddQueueNodes(q1,q2,newRow);

        result->pushBack(newRow);

        stackNode* next1 = nullptr;
        stackNode* next2 = nullptr;

        if (s1!=nullptr && s2!=nullptr)//Next Stack
        {
            next1 = s1->nextStackNode;
            next2 = s2->nextStackNode;
        }

        MoveStacks(next1,next2,result);

    }

    stack* addition(stack* mm)
    {
        stack* result=new stack();
        result->row = this->returnRow();
        result->col = this->returnCol();

        MoveStacks(m->stackHead,mm->stackHead,result);

        return result;
    }

    void SubtractQueueNodes(queueNode* q1, queueNode* q2, queue* result)
    {
        if (q1 == nullptr && q2 == nullptr)
        {
            return;
        }

        int total = 0;

        if (q1 != nullptr && q2 != nullptr)
        {
            total = q1->value - q2->value;
        }

        result->enqueue(total);

        queueNode* next1 = q1;
        queueNode* next2 = q2;

        if (q1 != nullptr && q2 != nullptr)
        {
            next1 = q1->nextQueueNode;
            next2 = q2->nextQueueNode;
        }
        SubtractQueueNodes(next1, next2, result);
    }

    void ChangeStacks(stackNode* s1, stackNode* s2, stack* result)
    {
        if (s1 == nullptr && s2 == nullptr)
        {
            return;
        }

        queue* newRow = new queue();

        queueNode* q1 = nullptr;
        queueNode* q2 = nullptr;

        if (s1 != nullptr && s2 != nullptr)
        {
            q1 = s1->queueHead->front;
            q2 = s2->queueHead->front;
        }

        SubtractQueueNodes(q1, q2, newRow);

        result->pushBack(newRow);

        stackNode* next1 = nullptr;
        stackNode* next2 = nullptr;

        if (s1 != nullptr && s2 != nullptr)
        {
            next1 = s1->nextStackNode;
            next2 = s2->nextStackNode;
        }

        ChangeStacks(next1, next2, result);
    }

    stack* subtraction(stack* mm)
    {
        stack* result = new stack();
        result->row = this->returnRow();
        result->col = this->returnCol();

        ChangeStacks(m->stackHead, mm->stackHead, result);

        return result;
    }

    int MultilpyQueueNodes(queueNode* q1, queueNode* q2)
    {
        if (q1 == nullptr || q2 == nullptr)
        {
            return 0;
        }

        return (q1->value * q2->value) + MultilpyQueueNodes(q1->nextQueueNode, q2->nextQueueNode);
    }

    void ExtractCol(stackNode* ptr, int colIndex, queue* resCol)
    {
        if (ptr == nullptr)
        {
            return;
        }

        queueNode* temp = ptr->queueHead->front;

        for (int i = 0; i < colIndex && temp != nullptr; i++)
        {
            temp = temp->nextQueueNode;
        }

        if (temp != nullptr)
        {
            resCol->enqueue(temp->value);
        }

        ExtractCol(ptr->nextStackNode, colIndex, resCol);
    }

    void MultiplyRowWithColumn(stackNode* s1, stack* s2, int totalCols, queue* newRow, int currentCol = 0)
    {
        if (currentCol == totalCols)
        {
            return;
        }

        queue* resCol = new queue();
        ExtractCol(s2->stackHead, currentCol, resCol);

        int val = MultilpyQueueNodes(s1->queueHead->front, resCol->front);
        newRow->enqueue(val);

        MultiplyRowWithColumn(s1, s2, totalCols, newRow, currentCol + 1);
    }

    void StackChange(stackNode* s1, stack* s2, stack* result)
    {
        if (s1 == nullptr)
        {
            return;
        }

        queue* newRow = new queue();
        MultiplyRowWithColumn(s1, s2, s2->col, newRow);
        result->pushBack(newRow);

        StackChange(s1->nextStackNode, s2, result);
    }

    stack* multiplication(stack* mm)
    {
        stack* result = new stack();
        result->row = m->row;
        result->col = mm->col;

        StackChange(m->stackHead, mm, result);

        return result;
    }

    void TransposeStackRecursively(stack* result, stackNode* head, int totalCols, int currentCol = 0)
    {
        if (currentCol == totalCols)
        {
            return;
        }

        queue* newRow = new queue();
        ExtractCol(head, currentCol, newRow);
        result->pushBack(newRow);
        TransposeStackRecursively(result, head, totalCols, currentCol + 1);

    }

    stack* transpose()
    {
        stack* result = new stack();
        result->col = m->row;
        result->row = m->col;

        TransposeStackRecursively(result, m->stackHead,m->col);

        return result;
    }

    void DivideQueueNodes(queueNode* q1,queueNode* q2,queue* resRow)
    {
        if (q1 == nullptr && q2 == nullptr)
        {
            return;
        }

        int total = 0;

        if (q1 != nullptr && q2 != nullptr)
        {
            if (q2->value!=0)
            {
                total = q1->value / q2->value;
            }
            else if (q2->value==0)
            {
                total = -0;
            }
            
        }

        resRow->enqueue(total);

        queueNode* next1 = q1;
        queueNode* next2 = q2;

        if (q1 != nullptr && q2 != nullptr)
        {
            next1 = q1->nextQueueNode;
            next2 = q2->nextQueueNode;
        }
        DivideQueueNodes(next1, next2, resRow);
    }

    void StackMove(stackNode* s1,stackNode* s2,stack* result)
    {
        if (s1 == nullptr && s2 == nullptr)
        {
            return;
        }

        queue* newRow = new queue();

        queueNode* q1 = nullptr;
        queueNode* q2 = nullptr;

        if (s1 != nullptr && s2 != nullptr)
        {
            q1 = s1->queueHead->front;
            q2 = s2->queueHead->front;
        }

        DivideQueueNodes(q1, q2, newRow);

        result->pushBack(newRow);

        stackNode* next1 = nullptr;
        stackNode* next2 = nullptr;

        if (s1 != nullptr && s2 != nullptr)
        {
            next1 = s1->nextStackNode;
            next2 = s2->nextStackNode;
        }

        StackMove(next1, next2, result);

    }

    stack* division(stack*mm)
    {
        stack* result = new stack();
        result->col = m->row;
        result->row = m->col;

        StackMove(m->stackHead,mm->stackHead,result);

        return result;
    }

    bool CompareRows(queueNode* temp,queueNode*  rand)
    {
        if (rand==nullptr)
        {
            return true;
        }

        if (temp==nullptr)
        {
            return false;
        }

        if (temp->value!=rand->value)
        {
            return false;
        }

        return CompareRows(temp->nextQueueNode,rand->nextQueueNode);

    }

    bool CompareSubMatrix(stackNode* head,stackNode* other,int CurrentCol )
    {
        if (other==nullptr)
        {
            return true;
        }

        if (head==nullptr)
        {
            return false;
        }

        queueNode* temp = head->queueHead->front;
        
        for (int i=0;i<CurrentCol && temp!=nullptr;i++)
        {
            temp = temp->nextQueueNode;
        }

        if(!CompareRows(temp,other->queueHead->front))
        {
            return false;
        }

        return CompareSubMatrix(head->nextStackNode,other->nextStackNode,CurrentCol);

    }

    bool FindSubatrix(stackNode* head, stackNode* other,int headCol,int otherCol, int currentRow=0,int CurrentCol=0)
    {
        if (head==nullptr || other==nullptr)
        {
            return false;
        }

        if (CurrentCol+otherCol>headCol)
        {
            return FindSubatrix(head->nextStackNode,other, headCol,otherCol,currentRow + 1,0);      //For Next Row
        }

        if (CompareSubMatrix(head,other,CurrentCol))
        {
            return true;
        }

        return FindSubatrix(head, other, headCol, otherCol, currentRow,CurrentCol+1);
    }

    bool IsSubMatrix(stack* mm)
    {
        if (mm==nullptr || m==nullptr)
        {
            return false;
        }

        if (mm->row > returnRow() || mm->col > returnCol())
        {
            return false;
        }

        return FindSubatrix(m->stackHead,mm->stackHead,m->col,mm->col);

    }

    int returnCol()
    {
        return m->col;
    }

    int returnRow()
    {
        return m->row;
    }

    stack* ReturnStack()
    {
        return m;
    }
};

int main()
{
    Matrix m1, m2, m3;

    m1.MatrixInput("m1.txt");
    cout << "Matrix 1:" << endl;
    m1.display();

    m2.MatrixInput("m2.txt");
    cout << "Matrix 2:" << endl;
    m2.display();

    m3.MatrixInput("m3.txt");
    cout << "Matrix 3:" << endl;
    m3.display();

    if (m1.returnCol() == m2.returnCol() && m1.returnRow() == m2.returnRow())
    {
        cout << "\nAddition Result:"<<endl;
        stack* addRes = m1.addition(m2.ReturnStack());
        addRes->Display();
    }
    else
    {
        cout << "\nAddition Not Possible"<<endl;
    }

    if (m1.returnCol() == m2.returnCol() && m1.returnRow() == m2.returnRow())
    {
        cout << "\nSubtraction Result:"<<endl;
        stack* subRes = m1.subtraction(m2.ReturnStack());
        subRes->Display();
    }
    else
    {
        cout << "\nSubtraction Not Possible"<<endl;
    }

    if (m1.returnCol() == m2.returnRow())
    {
        cout << "\nMultiplication Result:"<<endl;
        stack* mulRes = m1.multiplication(m2.ReturnStack());
        mulRes->Display();
    }
    else
    {
        cout << "\nMultiplication Not Possible"<<endl;
    }

    if (m1.returnCol() == m2.returnCol() && m1.returnRow() == m2.returnRow())
    {
        cout << "\nDivision Result:" << endl;
        stack* divRes = m1.division(m2.ReturnStack());
        divRes->Display();
    }
    else
    {
        cout << "\nDivision Not Possible" << endl;
    }

    cout << "\nTranspose of Matrix 1:"<<endl;
    stack* transRes = m1.transpose();
    transRes->Display();

    cout << "IsSubMatrix :" << m1.IsSubMatrix(m3.ReturnStack());

}
