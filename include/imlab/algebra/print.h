// ---------------------------------------------------------------------------
// IMLAB
// ---------------------------------------------------------------------------
#ifndef INCLUDE_IMLAB_ALGEBRA_PRINT_H_
#define INCLUDE_IMLAB_ALGEBRA_PRINT_H_
// ---------------------------------------------------------------------------
#include <memory>
#include <utility>
#include <vector>
#include "imlab/algebra/operator.h"
// ---------------------------------------------------------------------------
namespace imlab {
// ---------------------------------------------------------------------------
class Print: public Operator {
 protected:
    // Child operator
    std::unique_ptr<Operator> child_;

    // Required ius
    std::vector<const IU*> required_ius_;
    // Consumer
    Operator *consumer_;
    // Out stream
    std::ostream *out_;

 public:
    // Constructor
    explicit Print(std::unique_ptr<Operator> child, std::vector<const IU*> printedIUs)
        : child_(std::move(child)), required_ius_(std::move(printedIUs)) {}

    // Collect all IUs produced by the operator
    std::vector<const IU*> CollectIUs() override;

    // Prepare the operator
    void Prepare(const std::vector<const IU*> &required, Operator* consumer, std::ostream &out) override;
    // Produce all tuples
    void Produce() override;
    // Consume tuple
    void Consume(const Operator* child) override;

    void Execute(std::ostream &out) {
        Prepare(required_ius_, nullptr, out);
        Produce();
    }
};
// ---------------------------------------------------------------------------
}  // namespace imlab
// ---------------------------------------------------------------------------
#endif  // INCLUDE_IMLAB_ALGEBRA_PRINT_H_
// ---------------------------------------------------------------------------
