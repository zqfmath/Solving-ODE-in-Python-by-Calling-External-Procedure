//
// Created by Zqf on 3/20/20.
//

#ifndef ODE_PROJ_VEC_ODE_H
#define ODE_PROJ_VEC_ODE_H

// The vector class for system of ODE
template <class T>
class vec{
public:
    unsigned int len;
    T *vec_data;

    vec(unsigned int n){
        len=n;
        vec_data=new T[len];
    }

//initial data from array
    vec(unsigned int n, const T* data){
        len=n;
        vec_data=new T[len];
        for(unsigned int i=0;i<len;i++)
            vec_data[i]=data[i];
    }
    ~vec(){
        delete [] vec_data;
    }

    //overload different operators
    T& operator[](unsigned int i){
        return vec_data[i];
    }
    vec<T>& operator=(const vec<T> &x){
        for(unsigned i=0;i<len;i++)
            vec_data[i]=x.vec_data[i];
        return *this;
    }
    vec<T>& operator+(){
        return *this;
    }
    vec<T> operator+(const T &y){
        vec<T> result=vec(len,vec_data);
        for(unsigned int i=0;i<len;i++)
            result.vec_data[i]+=y;
        return result;
    }
    vec<T> operator+(const vec<T> &y){
        vec<T> result=vec(len,vec_data);
        for(unsigned int i=0;i<len;i++)
            result.vec_data[i]+=y.vec_data[i];
        return result;
    }
    vec<T> operator-(){
        vec<T> result=vec(len);
        for(unsigned int i=0;i<len;i++)
            result.vec_data[i]=-vec_data[i];
        return result;
    }

    vec<T> operator-(const T &y){
        vec<T> result=vec(len,vec_data);
        for(unsigned int i=0;i<len;i++)
            result.vec_data[i]-=y;
        return result;
    }

    vec<T> operator-(const vec<T> &y){
        vec<T> result=vec(len,vec_data);
        for(unsigned int i=0;i<len;i++)
            result.vec_data[i]-=y.vec_data[i];
        return result;
    }
    vec<T> operator*(const T &y){
        vec<T> result=vec(len,vec_data);
        for(unsigned int i=0;i<len;i++)
            result.vec_data[i]=vec_data[i]*y;
        return result;
    }
    T operator*(const vec<T> &y){
        T result=0;
        for(unsigned int i=0;i<len;i++)
            result+=vec_data[i]*y.vec_data[i];
        return result;
    }
    vec<T> operator/(const T &y){
        vec<T> result=vec(len,vec_data);
        for(unsigned int i=0;i<len;i++)
            result.vec_data[i]=vec_data[i]/y;
        return result;
    }

};


#endif //ODE_PROJ_VEC_ODE_H
