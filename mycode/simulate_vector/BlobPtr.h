#ifndef BLOBPTR_H
#define BLOBPTR_H

#include <memory>
#include <vector>
#include "Blob.h"
template <typename T>
class BlobPtr {
public:
    BlobPtr():curr(0){}
    BlobPtr(Blob<T> &a, size_t sz=0):
        wptr(a.data),curr(sz){}
    T& operator*() const{
        auto p=check(curr, "defeference past end");
        return (*p)[curr];
    }
    T* operator->() const{
        return & this->operator *();
    }
    BlobPtr& operator++(); //qian zhi yun suan fu
    BlobPtr& operator--();
    virtual ~BlobPtr()=default;
private:
    std::shared_ptr<std::vector<T>>
            check(std::size_t, const std::string&) const; 
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr; //current location of vector

};



#endif /* BLOBPTR_H */
