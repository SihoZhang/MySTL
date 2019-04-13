/* 
 * Author:Siho Zhang
 * Time:2019/04/12
 */
#ifndef __MYVECTOR__
#define __MYVECTOR__

namespace zsh{
    template <typename T>
    class MyVector{
    public:
        MyVector();
        MyVector(const unsigned& initSize);
        MyVector(const MyVector& vec);
        ~MyVector();
        void push_back(const T& data);
        void pop_back();
        T& operator[](const unsigned& index) const;
        const unsigned& size() const;
        const unsigned& capacity() const;
    private:
        T* pVec;
        unsigned nowSize;
        unsigned nowCapacity;
    };
    
    /*
     * definition
     */
    //default Constructor
    template <typename T>
    MyVector<T>::MyVector():pVec(NULL),nowSize(0),nowCapacity(0) 
    {
    }
    //Constructor with a number
    template <typename T>
    MyVector<T>::MyVector(const unsigned& initSize):nowSize(initSize),nowCapacity(2)
    {
        if(initSize > 0)
        {
            while(nowCapacity < initSize) nowCapacity *= 2;
            pVec = new T[nowCapacity];
        }
    }
    // Copy Constructor
    template <typename T>
    MyVector<T>::MyVector(const MyVector& vec)
    {
        nowSize = vec.nowSize;
        nowCapacity = vec.nowCapacity;
        pVec = new T[nowCapacity];
        for (int i =0; i < nowSize; i++)
        {
            *(pVec + i) = *(vec.pVec + i);
        }
    }
    //Destructor
    template <typename T>
    MyVector<T>::~MyVector()
    {
        delete[] pVec;
    }
    //push_back
    template <typename T>
    void MyVector<T>::push_back(const T& data)
    {
        if(nowCapacity == 0){
             nowCapacity=2;
             pVec = new T[nowCapacity];
        }
        if(nowSize == nowCapacity) {
            nowCapacity *= 2;
            T* pTemp = new T[nowCapacity];
            for(int i=0; i < nowSize; i++){
                *(pTemp + i) = *(pVec + i);
            }
            *(pTemp + nowSize) = data;
            nowSize++;
            delete[] pVec;
            pVec = pTemp;
        }
        else {
            *(pVec + nowSize) = data;
            nowSize++;
        }
    }
    //pop_back
    template <typename T>
    void MyVector<T>::pop_back()
    {
        if (nowSize > 0)
            nowSize--;
    }
    // []
    template <typename T>
    T& MyVector<T>::operator[](const unsigned& index) const
    {
        return *(pVec + index);
    }
    //size()
    template <typename T>
    const unsigned& MyVector<T>::size() const
    {
        return nowSize;
    }
    //nowCapacity()
    template <typename T>
    const unsigned& MyVector<T>::capacity() const
    {
        return nowCapacity;
    }
    
}
#endif  /* MYVECTOR */
