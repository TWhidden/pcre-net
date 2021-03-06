
#pragma once

#include "Stdafx.h"
#include "CalloutData.h"
#include "PatternOptions.h"

namespace PCRE {
	namespace Wrapper {

		ref class MatchData;
		ref class JitStack;

		public ref class MatchContext sealed
		{
		public:
			__clrcall MatchContext();
			__clrcall ~MatchContext();
			__clrcall !MatchContext();

			property System::String^ Subject;
			property int StartIndex;
			property PatternOptions AdditionalOptions;
			property CalloutDelegate^ CalloutHandler;
			property uint32_t MatchLimit { void set(uint32_t); }
			property uint32_t DepthLimit { void set(uint32_t); }
			property uint32_t HeapLimit { void set(uint32_t); }
			property uint32_t OffsetLimit { void set(uint32_t); }
			property JitStack^ JitStack { void set(PCRE::Wrapper::JitStack^); }

			property uint32_t DfaMaxResults;
			property uint32_t DfaWorkspaceSize;

		internal:
			void __clrcall EnableCallout(void* contextPtr);

			property MatchData^ Match;

			property pcre2_match_context* Context {
				pcre2_match_context* __clrcall get() { return _ctx; }
			}

		private:
			pcre2_match_context* _ctx;
		};
	}
}
