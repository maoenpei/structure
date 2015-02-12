#ifndef __BASE_TRANSFORMER_H__
#define __BASE_TRANSFORMER_H__

#include "ITransformer.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include <vector>

namespace engine{

	class CTransformer : public core::CRefObject, public virtual ITransformer
	{
	public:
		virtual void setMode(unsigned int mode);

		virtual void push();
		virtual void pop();
		virtual void contact(const TAffinef &aff);
		virtual void load(const TAffinef &aff);
		virtual void get(TAffinef &aff);
		virtual void contact(const TMatrixf &mat);
		virtual void load(const TMatrixf &mat);
		virtual void get(TMatrixf &mat);
		
		CTransformer();

	private:
		struct TransformerEntry;
		std::vector<core::TAuto<TransformerEntry> > Stack;
		int TailIndex;
		core::TAuto<TransformerEntry> head;
	};
	
};

#endif


