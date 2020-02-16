//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include <common/declarations.h>
#include <collections/arrays.h>
#include <collections/pair.h>

/** Tensor class for ML */
struct tensor {
    /** Iterator on tensor sub-dimensions */
    struct iterator {
        vec cref elements;
        nat start{0};
        nat step;

        dim cref dimensions;

        tensor operator*() { return tensor(slice(elements, start, step), slice(dimensions, 1)); }
        inline iterator ref operator++() {
            start += step;
            return *this;
        }
        bool operator!=(iterator cref other) { return start != other.start; }

        explicit iterator(tensor cref parent, nat start = 0) :
                elements(parent.elements), cinits(start), step{parent.dim_sizes[0]}, cinit(dimensions, parent) {}
    };

    /* Fields */
    /** Elements of the tensor. */
    vec elements;
    /** Dimensions of the tensor. */
    dim dimensions;
    /** Number of elements in each dimension. */
    dim dim_sizes{0};

    /* Methods */
    /** Number of dimensions in a tensor. */
    [[nodiscard]] inline nat rank() const { return dimensions.size; }
    /** Total number of elements. */
    [[nodiscard]] inline nat elements_count() const { return elements.size; }
    /** Accesses element at composite index at dimensions. */
    [[nodiscard]] num ref operator[](dim cref) const;
    /** Accesses element at index at flattened collections. */
    [[nodiscard]] inline num ref operator[](nat i) const { return elements[i]; }
    /** Returns the number of sub-dimensions. */
    [[nodiscard]] inline nat subdim_count() const { return dimensions[0]; }
    /** Returns true if is 1D tensor. */
    [[nodiscard]] inline bool is_vector() const { return rank() == 1; }
    /** Returns vector value of a tensor. */
    [[nodiscard]] inline vec vector_value() const { return elements; }
    /** Returns true if is 0D tensor. */
    [[nodiscard]] inline bool is_scalar() const { return rank() == 0; }
    /** Returns scalar value of a tensor. */
    [[nodiscard]] inline num scalar_value() const { return elements[0]; }
    /** Creates a vector from reinterpretation of dimensions. */
    [[nodiscard]] tensor view(idim cref dim_order) const;

    /* Constructors */
    /** Creates zero tensor. */
    inline tensor() = default;
    /** Copies elements of another tensor. */
    inline tensor(tensor cref other) = default;
    /** Moves elements of another tensor. */
    inline tensor(tensor mref other) noexcept : minit(elements, other), minit(dimensions, other), minit(dim_sizes, other) {}

    explicit tensor(num scalar) : elements{scalar}, dimensions{0}, dim_sizes{0} {}
    /** Creates 1D tensor from numbers. */
    explicit tensor(vec elements) : minits(elements), dimensions{this->elements.size}, dim_sizes{1} {}
    /** Creates 1D tensor from numbers. */
    tensor(params<num> numbers) : tensor(vec(numbers)) {}
    /** Creates a tensor with elements and specific dimensions. */
    tensor(vec elements, dim dimensions) : minits(elements), minits(dimensions), dim_sizes{dimensions_sizes(this->dimensions)} {}
    /** Creates a tensor with elements and specific dimensions. */
    tensor(params<num> numbers, dim dimensions) : tensor(vec(numbers), std::move(dimensions)) {}
    /** Creates a tensor by flattening inner tensors. */
    tensor(params<tensor> tensors);
    /** Creates a tensor with specified dimensions, filled with the same value */
    static tensor of(dim cref dimensions, num value);

    /* Iteration */
    [[nodiscard]] inline iterator begin() const { return iterator(*this); }
    [[nodiscard]] inline iterator end() const { return iterator(*this, elements_count()); }
};


#define transform_op inline tensor operator
#define inplace_op inline tensor ref operator
#define defer_op(operator) { return {a.elements operator b, a.dimensions}; }
#define defer_inline(operator) { a.elements operator b.elements; return a;}
#define arg tensor cref

#define defer_op2(operator) { return {a.elements operator b.elements, a.dimensions}; }

/* Operators */
// todo: check scalars
transform_op-(arg a) { return {-a.elements, a.dimensions}; }

transform_op+(arg a, arg b) defer_op2(+)
transform_op-(arg a, arg b) defer_op2(-)

transform_op+(arg a, num b) defer_op(+)
transform_op-(arg a, num b) defer_op(-)
transform_op*(arg a, num b) defer_op(*)
transform_op*(num b, arg a) defer_op(*)
transform_op/(arg a, num b) defer_op(/)

transform_op*(arg a, arg b) {
    if (a.is_scalar())
        if (b.is_scalar()) return tensor(a.scalar_value() * b.scalar_value());
        else return a.scalar_value() * b;
    if (b.is_scalar())
        return a * b.scalar_value();

    return {a.elements * b.elements, a.dimensions};
} // hadamard
transform_op/(arg a, arg b) {
    require(!a.is_scalar() || b.is_scalar(), "Cannot divide scalar tensor by non-scalar tensor");

    if (a.is_scalar())
        if (b.is_scalar()) return tensor(a.scalar_value() / b.scalar_value());

    if (b.is_scalar())
        return a / b.scalar_value();

    return {a.elements / b.elements, a.dimensions};
} // hadamard

inplace_op+=(tensor ref a, arg b) defer_inline(+=)
inplace_op-=(tensor ref a, arg b) defer_inline(-=)
inplace_op*=(tensor ref a, arg b) defer_inline(*=)
inplace_op/=(tensor ref a, arg b) defer_inline(/=)

#undef transform_op
#undef inplace_op
#undef defer_op
#undef defer_inline
#undef defer_op2
#undef arg

/**
 * Tensor dot product
 * @param a First tensor
 * @param b Second tensor
 * @param dim_a Dimension to sum over on a
 * @param dim_b Dimension to sum over on b
 */
//tensor dot(tensor cref a, tensor cref b, nat dim_a, nat dim_b);
/**
 * Tensor dot product
 * @param a First tensor
 * @param b Second tensor
 * @param dim_a Dimensions to sum over
 * @param dim_b Dimensions to sum over
 */
//tensor dot(tensor cref a, tensor cref b, dim cref dim_a, dim cref dim_b);
/**
 * Tensor (outer) product for vecotrs and tensors
 * @param a
 * @param b
 * @return
 */
//tensor outer(tensor cref a, tensor cref b);


/* Functions on tensors */
/** Sums all elements of a tensor */
num sum(tensor cref t);
/** Sums tensors along dimensions */
tensor sum(tensor cref t, nat dimension);
/** Average of all elements of a tensor */
num mean(tensor cref t);

tensor extend(tensor cref a, tensor cref b);
///** Multiplies elements of two tensors. */
//[[nodiscard]] tensor mul(tensor_view cref a, tensor_view cref b);
/** Multiplies elements of two tensors. */
//[[nodiscard]] tensor mul(tensor cref a, tensor cref b, dim cref, dim cref);
tensor dot(tensor cref a, tensor cref b, pair<idim, idim> cref views = {{-1},
                                                                        {0}});
tensor low_dot(tensor cref a, tensor cref b);


#endif //CALCULUS_TENSOR_H
