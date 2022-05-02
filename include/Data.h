#ifndef DATA_H
#define DATA_H

namespace ds {

class Data {
 public:
  explicit Data (int id = 0) : id_(id) {}

  friend bool operator<(const Data& l, const Data& r){
    return l.id_ < r.id_;
  }

  friend bool operator>(const Data& l, const Data& r){
    return !(l < r);
  }

  friend bool operator==(const Data& l, const Data& r){
    return l.id_ == r.id_;
  }

  friend bool operator!=(const Data& l, const Data& r){
    return !(l == r);
  }

 private:
  int id_;
};

}

#endif // DATA_H
