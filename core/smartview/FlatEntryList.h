#pragma once
#include <core/smartview/block/block.h>
#include <core/smartview/EntryIdStruct.h>
#include <core/smartview/block/blockBytes.h>
#include <core/smartview/block/blockT.h>

namespace smartview
{
	struct FlatEntryID
	{
		std::shared_ptr<blockT<DWORD>> dwSize = emptyT<DWORD>();
		std::shared_ptr<EntryIdStruct> lpEntryID;

		std::shared_ptr<blockBytes> padding = emptyBB();

		FlatEntryID(const std::shared_ptr<binaryParser>& parser);
	};

	class FlatEntryList : public block
	{
	private:
		void parse() override;
		void parseBlocks() override;

		std::shared_ptr<blockT<DWORD>> m_cEntries = emptyT<DWORD>();
		std::shared_ptr<blockT<DWORD>> m_cbEntries = emptyT<DWORD>();
		std::vector<std::shared_ptr<FlatEntryID>> m_pEntryIDs;
	};
} // namespace smartview