////
//// Created by Vladyslav Yazykov on 06/02/2020.
////
//
//#include <index_iterable.h>
//
//
//using ind_itb = __indices_iterable;
//using ind_itr = __indices_iterable::__indices_iterator;
//
///* Indices iterable */
//// Iterable constructor
//__indices_iterable::__indices_iterable(vnat dimensions) : move_init_s(dimensions) {}
//// Constructor
//ind_itb::__indices_iterator::__indices_iterator(cvnat dimensions) : copy_init_s(dimensions), indices(this->dimensions.size()) {}
//ind_itb::__indices_iterator::__indices_iterator(cvnat dimensions, vnat indices) : copy_init_s(dimensions), move_init_s(indices) {}
//// Yielding value
//cvnat ind_itr::operator*() const { return indices; }
//// Moving forward
//const ind_itr &ind_itr::operator++() {
//    var dim{dimensions.size() - 1};
//    while (dim > 0 && indices[dim] >= dimensions[dim] - 1)
//        indices[dim--] = 0;
//
//    indices[dim] += 1;
//    return *this;
//}
//bool ind_itr::operator!=(c__indices_iterator other) const { return indices != other.indices; }
//// Begin, End
//ind_itr ind_itb::begin() const { return ind_itr(dimensions); }
//ind_itr ind_itb::end() const {
//    if (!dimensions.empty()) {
//        vnat indices(dimensions.size()); // indices should be zero everywhere...
//        indices[0] = dimensions[0];         // except for the first dimension
//        return ind_itr(dimensions, indices);
//    }
//    return ind_itr({}, {});
//}
