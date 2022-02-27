#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;



class Pos2D {
  int x_, y_;
public:
  Pos2D(int x, int y) : x_(x), y_(y) {};
  Pos2D(const Pos2D & pos) { x_ = pos.x_; y_ = pos.y_; }
  Pos2D operator+ (const Pos2D rhs) const { return Pos2D(x_+rhs.x_, y_+rhs.y_); }
  bool operator== (Pos2D p) const { return ( (p.x_==x_) && (p.y_==y_) ); }

  bool operator< (const Pos2D p) const {
    if (x_ < p.x_) return true;
    else if (x_ > p.x_) return false;
    else return (y_ < p.y_);
  }

  void print() const { cout << x_ << " " << y_ << endl; }
};


class Walk {
protected:
  Pos2D pos_;
public:
  Walk(Pos2D p = Pos2D(0,0)) : pos_(p) {};
  Pos2D position() const { return pos_; }

  virtual void operator+= (Pos2D delta) { pos_ = pos_ + delta; }

  void print() const { pos_.print(); }
};


class AvoidingWalk : public Walk {
  set<Pos2D> visited_;
public:
  AvoidingWalk() {
    visited_.insert(Pos2D(0,0));
  }
  void operator+= (Pos2D delta) {
    Pos2D newpos = pos_ + delta;
    auto it = visited_.find(newpos);
    if (it == visited_.end()) {
      visited_.insert(newpos);
      // oppure, meglio:
      // visited_.insert(it,newpos);
      pos_ = newpos;
    }
  }
};

class WeaklyAvoidingWalk : public AvoidingWalk {
  double prob_;
public:
  WeaklyAvoidingWalk(double p) : prob_(p) {}
  void operator+= (Pos2D delta) {
    if (drand48() < prob_) AvoidingWalk::operator+= (delta);
    else Walk::operator+= (delta);
  }
};


bool compare(Walk & w1, Walk & w2) {
  for (long i = 0; i<100; ++i) {
    int dx = (drand48()<0.5)?1:-1;
    int dy = (drand48()<0.5)?1:-1;
    /* testo B
    int dx, dy;
    double d = drand48();
    if (d<0.25) { dx=1; dy=0; }
    else if (d<0.5) { dx=-1; dy=0; }
    else if (d<0.75) { dx=0; dy=1; }
    else { dx=0; dy=-1; }
    */
    Pos2D delta(dx,dy);
    w1 += delta; w2 += delta;
  }
  return (w1.position()==w2.position());
}


int main() {

  srand48(time(NULL));

  Walk w;  // oppure AvoidingWalk
  Pos2D pos(0,0); long step = 0;
  while ( !(pos==Pos2D(-5,17)) ) {
    w += Pos2D( floor(2*cos(step/5.)+0.5), floor(2*sin(step/5.)+0.5) );
    pos = w.position();
    ++step;
  }
  cout << step << endl;
  
  //
  long tot = 0;
  for (long i =0; i<10000; ++i) {
    WeaklyAvoidingWalk w1(0.087);
    Walk w2;
    if (compare(w1,w2)) ++tot;
  }
  cout << tot/10000. << endl;
  
  


}
