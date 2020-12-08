#include <functional>

#include "coordinate.cpp"

class box_iterator
{
public:
  // The following is not strictly necessary for our code
  // however if you want to have an iterator confirming to the
  // c++ standard you need this.
  using iterator_category = std::forward_iterator_tag;
  using value_type = point2d;
  // Has no sense for forward iterators but must be specified for
  // certain platforms in order to compile (g++ for instance)
  using difference_type = void;
  using pointer = point2d *;
  using reference = point2d &;

  box_iterator(coord x_beg, coord x_end, coord y_beg, coord y_end)
      : x_beg_(x_beg), x_end_(x_end), y_beg_(y_beg), y_end_(y_end),
        c_pos_(point2d({x_beg, y_beg})){};

  box_iterator(coord x_beg, coord x_end, coord y_beg, coord y_end,
               point2d char_pos)
      : x_beg_(x_beg), x_end_(x_end), y_beg_(y_beg), y_end_(y_end),
        c_pos_(char_pos){};

  box_iterator(const point2d &lower_left, const point2d &upper_right)
      : x_beg_(lower_left.x), x_end_(upper_right.x), y_beg_(lower_left.y),
        y_end_(upper_right.y), c_pos_(point2d({lower_left.x, lower_left.y})){};
  // Create the box from the lower_left corner (belongs to the box)
  // and the upper_right corner (just outside the box).

  // todo possible others for convenience.

  void reset();

  box_iterator *operator*(box_iterator &o)
  {
    return &o;
  }

  box_iterator &operator++()
  {
    if (c_pos_.x < x_end_ - 1)
    {
      c_pos_.x++;
    }
    else if (c_pos_.x == x_end_ - 1 && c_pos_.y < y_end_ - 1)
    {
      c_pos_.y++;
      c_pos_.x = x_beg_;
    }
  }

  bool operator==(const box_iterator &o) const { return !(operator!=(o)); }

  bool operator!=(const box_iterator &o) const
  {
    return o.x_beg_ != x_beg_ || o.y_beg_ != y_beg_ || o.x_end_ != x_end_ ||
           o.y_end_ != y_end_;
  }

  // Dereference : use the operator*() to generate a point
  // from current iterator.

  // Convenience functions.
  point2d get_c_pos() const { return c_pos_; }

  // is_done returns true if the current positions
  // corresponds to the end position.
  bool is_done() const
  {
    // TODO.
    return true;
  }

protected:
  coord x_beg_, x_end_, y_beg_, y_end_;
  point2d c_pos_;
};
