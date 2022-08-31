#ifndef MulOperator_hpp
#define MulOperator_hpp

#include "ast/Node.hpp"
#include "ast/Context.hpp"

class MulOperator : public Node
{
public:
  // Constructors
  MulOperator(NodePtr Left, NodePtr Right);

  // Destructor
  virtual ~MulOperator();

  // Visualising
  void generateParser(std::ostream &dst, std::string indent) const override;

  // MIPS
  void generateMIPS(std::string indent, int destReg, ContextPtr frameContext) const override;
  void generateMIPSDouble(std::string indent, int destReg, ContextPtr frameContext) const override;

  // Functions
  bool isAssignmentExp() const override;
  void countFunctionParameter(int* functionCallParameterOffset) const override;
  int getValue() const override;
  enum Specifier returnType() const override;

  // Context
  void generateContext(ContextPtr frameContext, int parameterOffset, bool isGlobal  ) override;



protected:
  ContextPtr blockContext;
  enum Specifier type;
};

#endif