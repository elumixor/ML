//
// Created by vlado on 2/2/20.
//

#ifndef CALCULUS_TENSOR_H
#define CALCULUS_TENSOR_H

#include <declarations.h>
#include <arrays/arrays.h>

/** Tensor class for ML */
struct tensor {
    /** Iterator on tensor sub-dimenions */
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
    /** Number of dimensions in a tensor. Same as dimensions.size. */
    [[nodiscard]] inline nat rank() const { return dimensions.size; }
    /** Total number of elements. */
    [[nodiscard]] inline nat elements_count() const { return elements.size; }
    /** Accesses element at indices at dimensions. */
    [[nodiscard]] num ref operator[](dim cref) const;
    /** Accesses element at index at flattened array. */
    [[nodiscard]] inline num ref operator[](nat i) const { return elements[i]; }
    /** Returns the number of sub-dimensions. */
    [[nodiscard]] inline nat subdim_count() const { return dimensions[0]; }
    /** Returns true if tensor only contains one or zero dimensions. */
    [[nodiscard]] inline bool is_vector() const { return rank() < 2; }
    /** Creates a vector from reinterpretation of dimensions. */
    [[nodiscard]] tensor view(dim cref dim_order) const;

    /* Constructors */
    /** Creates zero tensor. */
    inline tensor() = default;
    /** Copies elements of another tensor. */
    inline tensor(tensor cref other) = default;
    /** Moves elements of another tensor. */
    inline tensor(tensor mref other) noexcept : minit(elements, other), minit(dimensions, other), minit(dim_sizes, other) {}

    /** Creates 1D tensor from numbers. */
    explicit tensor(vec elements) : minits(elements), dimensions{this->elements.size}, dim_sizes{this->elements.size} {}
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

    /* Iteration methods */
    [[nodiscard]] inline iterator begin() const { return iterator(*this); }
    [[nodiscard]] inline iterator end() const { return iterator(*this, elements_count()); }
};

/* Methods on tensor */
///** Creates a tensor with a different dimensions ordering. */
//tensor view(dim cref dimension_indices);
///** Creates a tensor view with elements flattened. */
//vec flat();
///** Creates a tensor view with elements flattened with a different dimensions ordering */
//vec flat(dim cref dimension_indices);

/* Operators*/

//tensor operator-(tensor cref a);
//tensor operator+(tensor cref a, tensor cref b);
//tensor &operator+=(tensor ref a, tensor cref b);
//tensor &operator-=(tensor ref a, tensor cref b);
//tensor operator-(tensor cref a, tensor cref b);
//tensor operator+(tensor cref a, scalar b);
//tensor operator-(tensor cref a, scalar b);
//tensor operator*(tensor cref a, scalar b);
//tensor operator*(tensor cref a, tensor cref b); // hadamard
//tensor operator*(scalar b, tensor cref a);
//tensor operator/(tensor cref a, scalar b);


#endif //CALCULUS_TENSOR_H
