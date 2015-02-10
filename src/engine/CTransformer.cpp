

#include "CTransformer.h"
#include <assert.h>

namespace engine{

struct CTransformer::TransformerEntry : public core::CRefObject
{
	unsigned int mode;
	union{
		TAffinef * af;
		TMatrixf * mf;
	}tf;
	TransformerEntry(unsigned int _mode) : mode(_mode)
	{
		if (mode == TransformMode_2D){
			tf.af = new TAffinef;
		}else{
			tf.mf = new TMatrixf;
		}
	}
	~TransformerEntry()
	{
		if (mode == TransformMode_2D){
			delete tf.af;
		}else{
			delete tf.mf;
		}
	}
	void assign(const TAffinef &af){
		tf.af = new TAffinef(af);
	}
	void assign(const TMatrixf &mf){
		tf.mf = new TMatrixf(mf);
	}
};

CTransformer::CTransformer()
	: TailIndex(0)
{
	head = new TransformerEntry(TransformMode_2D);
}

void CTransformer::push()
{
	if (TailIndex < (int)Stack.size()){
		Stack[TailIndex++] = head;
	}else{
		TailIndex++;
		Stack.push_back(head);
	}
}

void CTransformer::pop()
{
	assert(TailIndex > 0);
	head = Stack[--TailIndex];
	Stack[TailIndex] = 0;
}

void CTransformer::setMode(unsigned int mode)
{
	head = new TransformerEntry(mode);
}

void CTransformer::contact(const TAffinef & aff)
{
	assert(head->mode == TransformMode_2D);
	TAffinef af;
	head->tf.af->contact(af, aff);
	head->assign(af);
}

void CTransformer::load(const TAffinef & aff)
{
	assert(head->mode == TransformMode_2D);
	head->assign(aff);
}

void CTransformer::get(TAffinef & aff)
{
	assert(head->mode == TransformMode_2D);
	aff = *head->tf.af;
}

void CTransformer::contact(const TMatrixf & mat)
{
	assert(head->mode == TransformMode_3D);
	TMatrixf mf;
	head->tf.mf->contact(mf, mat);
	head->assign(mf);
}

void CTransformer::load(const TMatrixf & mat)
{
	assert(head->mode == TransformMode_3D);
	head->assign(mat);
}

void CTransformer::get(TMatrixf & mat)
{
	assert(head->mode == TransformMode_3D);
	mat = *head->tf.mf;
}

};


