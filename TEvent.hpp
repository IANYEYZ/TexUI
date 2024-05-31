#ifndef _TEXUI_EVENT_H_
#define _TEXUI_EVENT_H_

typedef void *ANYTYPE;
template <typename T>
T transany(ANYTYPE at){
	return (T)((long long)(at));
}
#define transepara transany

typedef string EVENT;
typedef ANYTYPE EPARA;
typedef void(*EFUNC)(EPARA);
typedef void(*EFUNC_NOPARA)();
typedef queue<EFUNC> EQUEUE;
struct EVENTINFO{
	EVENT ev;
	EPARA pa;
	EVENTINFO(){}
	EVENTINFO(const EVENT &_e,const EPARA _p):
		ev(_e),pa(_p){} 
};
 
map<EVENT,EQUEUE> events;

void syncevent(EVENT ev,EPARA para){
	EQUEUE eq=events[ev];
	while(!eq.empty()){
		EFUNC ef=eq.front();
		ef(para);
		eq.pop();
	}
} 
unsigned __stdcall evthread(void *info){
	EVENTINFO *ei=(EVENTINFO*)info;
	syncevent(ei->ev,ei->pa);
	delete ei;
	return 0;
}
void asyncevent(EVENT ev,EPARA para){
	unsigned tID;
	EVENTINFO *ei=new EVENTINFO(ev,para);
	_beginthreadex(NULL,0,evthread,ei,0,&tID);
}

void tbind(EVENT ev,EFUNC fun){
	events[ev].push(fun);
}
void bind(EVENT ev,EFUNC fun){
	tbind(ev,fun);
}

#endif
