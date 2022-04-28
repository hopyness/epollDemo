// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: client_server.proto

#include "client_server.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace PB {
namespace Client_Server {
constexpr Login::Login(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : uname_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , pwd_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct LoginDefaultTypeInternal {
  constexpr LoginDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~LoginDefaultTypeInternal() {}
  union {
    Login _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT LoginDefaultTypeInternal _Login_default_instance_;
constexpr Logout::Logout(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized){}
struct LogoutDefaultTypeInternal {
  constexpr LogoutDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~LogoutDefaultTypeInternal() {}
  union {
    Logout _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT LogoutDefaultTypeInternal _Logout_default_instance_;
constexpr FindAll::FindAll(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized){}
struct FindAllDefaultTypeInternal {
  constexpr FindAllDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~FindAllDefaultTypeInternal() {}
  union {
    FindAll _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT FindAllDefaultTypeInternal _FindAll_default_instance_;
constexpr FindList::FindList(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : listid_()
  , _listid_cached_byte_size_(0){}
struct FindListDefaultTypeInternal {
  constexpr FindListDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~FindListDefaultTypeInternal() {}
  union {
    FindList _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT FindListDefaultTypeInternal _FindList_default_instance_;
}  // namespace Client_Server
}  // namespace PB
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_client_5fserver_2eproto[4];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_client_5fserver_2eproto[4];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_client_5fserver_2eproto = nullptr;

const uint32_t TableStruct_client_5fserver_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::PB::Client_Server::Login, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::PB::Client_Server::Login, uname_),
  PROTOBUF_FIELD_OFFSET(::PB::Client_Server::Login, pwd_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::PB::Client_Server::Logout, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::PB::Client_Server::FindAll, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::PB::Client_Server::FindList, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::PB::Client_Server::FindList, listid_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::PB::Client_Server::Login)},
  { 8, -1, -1, sizeof(::PB::Client_Server::Logout)},
  { 14, -1, -1, sizeof(::PB::Client_Server::FindAll)},
  { 20, -1, -1, sizeof(::PB::Client_Server::FindList)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::PB::Client_Server::_Login_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::PB::Client_Server::_Logout_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::PB::Client_Server::_FindAll_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::PB::Client_Server::_FindList_default_instance_),
};

const char descriptor_table_protodef_client_5fserver_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\023client_server.proto\022\020PB.Client_Server\""
  "C\n\005Login\022\r\n\005uname\030\001 \001(\t\022\013\n\003pwd\030\002 \001(\t\"\036\n\005"
  "MsgId\022\n\n\006PROTO3\020\000\022\t\n\002Id\020\241\313\230\001\"(\n\006Logout\"\036"
  "\n\005MsgId\022\n\n\006PROTO3\020\000\022\t\n\002Id\020\242\313\230\001\")\n\007FindAl"
  "l\"\036\n\005MsgId\022\n\n\006PROTO3\020\000\022\t\n\002Id\020\243\313\230\001\":\n\010Fin"
  "dList\022\016\n\006listId\030\001 \003(\005\"\036\n\005MsgId\022\n\n\006PROTO3"
  "\020\000\022\t\n\002Id\020\244\313\230\001b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_client_5fserver_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_client_5fserver_2eproto = {
  false, false, 261, descriptor_table_protodef_client_5fserver_2eproto, "client_server.proto", 
  &descriptor_table_client_5fserver_2eproto_once, nullptr, 0, 4,
  schemas, file_default_instances, TableStruct_client_5fserver_2eproto::offsets,
  file_level_metadata_client_5fserver_2eproto, file_level_enum_descriptors_client_5fserver_2eproto, file_level_service_descriptors_client_5fserver_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_client_5fserver_2eproto_getter() {
  return &descriptor_table_client_5fserver_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_client_5fserver_2eproto(&descriptor_table_client_5fserver_2eproto);
namespace PB {
namespace Client_Server {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Login_MsgId_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_client_5fserver_2eproto);
  return file_level_enum_descriptors_client_5fserver_2eproto[0];
}
bool Login_MsgId_IsValid(int value) {
  switch (value) {
    case 0:
    case 2500001:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr Login_MsgId Login::PROTO3;
constexpr Login_MsgId Login::Id;
constexpr Login_MsgId Login::MsgId_MIN;
constexpr Login_MsgId Login::MsgId_MAX;
constexpr int Login::MsgId_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Logout_MsgId_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_client_5fserver_2eproto);
  return file_level_enum_descriptors_client_5fserver_2eproto[1];
}
bool Logout_MsgId_IsValid(int value) {
  switch (value) {
    case 0:
    case 2500002:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr Logout_MsgId Logout::PROTO3;
constexpr Logout_MsgId Logout::Id;
constexpr Logout_MsgId Logout::MsgId_MIN;
constexpr Logout_MsgId Logout::MsgId_MAX;
constexpr int Logout::MsgId_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* FindAll_MsgId_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_client_5fserver_2eproto);
  return file_level_enum_descriptors_client_5fserver_2eproto[2];
}
bool FindAll_MsgId_IsValid(int value) {
  switch (value) {
    case 0:
    case 2500003:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr FindAll_MsgId FindAll::PROTO3;
constexpr FindAll_MsgId FindAll::Id;
constexpr FindAll_MsgId FindAll::MsgId_MIN;
constexpr FindAll_MsgId FindAll::MsgId_MAX;
constexpr int FindAll::MsgId_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* FindList_MsgId_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_client_5fserver_2eproto);
  return file_level_enum_descriptors_client_5fserver_2eproto[3];
}
bool FindList_MsgId_IsValid(int value) {
  switch (value) {
    case 0:
    case 2500004:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr FindList_MsgId FindList::PROTO3;
constexpr FindList_MsgId FindList::Id;
constexpr FindList_MsgId FindList::MsgId_MIN;
constexpr FindList_MsgId FindList::MsgId_MAX;
constexpr int FindList::MsgId_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class Login::_Internal {
 public:
};

Login::Login(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:PB.Client_Server.Login)
}
Login::Login(const Login& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  uname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    uname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_uname().empty()) {
    uname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_uname(), 
      GetArenaForAllocation());
  }
  pwd_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    pwd_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_pwd().empty()) {
    pwd_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_pwd(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:PB.Client_Server.Login)
}

inline void Login::SharedCtor() {
uname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  uname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
pwd_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  pwd_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Login::~Login() {
  // @@protoc_insertion_point(destructor:PB.Client_Server.Login)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Login::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  uname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  pwd_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Login::ArenaDtor(void* object) {
  Login* _this = reinterpret_cast< Login* >(object);
  (void)_this;
}
void Login::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Login::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Login::Clear() {
// @@protoc_insertion_point(message_clear_start:PB.Client_Server.Login)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  uname_.ClearToEmpty();
  pwd_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Login::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string uname = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_uname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "PB.Client_Server.Login.uname"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string pwd = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_pwd();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "PB.Client_Server.Login.pwd"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Login::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:PB.Client_Server.Login)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string uname = 1;
  if (!this->_internal_uname().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_uname().data(), static_cast<int>(this->_internal_uname().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "PB.Client_Server.Login.uname");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_uname(), target);
  }

  // string pwd = 2;
  if (!this->_internal_pwd().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_pwd().data(), static_cast<int>(this->_internal_pwd().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "PB.Client_Server.Login.pwd");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_pwd(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PB.Client_Server.Login)
  return target;
}

size_t Login::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:PB.Client_Server.Login)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string uname = 1;
  if (!this->_internal_uname().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_uname());
  }

  // string pwd = 2;
  if (!this->_internal_pwd().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_pwd());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Login::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Login::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Login::GetClassData() const { return &_class_data_; }

void Login::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Login *>(to)->MergeFrom(
      static_cast<const Login &>(from));
}


void Login::MergeFrom(const Login& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PB.Client_Server.Login)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_uname().empty()) {
    _internal_set_uname(from._internal_uname());
  }
  if (!from._internal_pwd().empty()) {
    _internal_set_pwd(from._internal_pwd());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Login::CopyFrom(const Login& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PB.Client_Server.Login)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Login::IsInitialized() const {
  return true;
}

void Login::InternalSwap(Login* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &uname_, lhs_arena,
      &other->uname_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &pwd_, lhs_arena,
      &other->pwd_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata Login::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_client_5fserver_2eproto_getter, &descriptor_table_client_5fserver_2eproto_once,
      file_level_metadata_client_5fserver_2eproto[0]);
}

// ===================================================================

class Logout::_Internal {
 public:
};

Logout::Logout(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena, is_message_owned) {
  // @@protoc_insertion_point(arena_constructor:PB.Client_Server.Logout)
}
Logout::Logout(const Logout& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:PB.Client_Server.Logout)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Logout::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Logout::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata Logout::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_client_5fserver_2eproto_getter, &descriptor_table_client_5fserver_2eproto_once,
      file_level_metadata_client_5fserver_2eproto[1]);
}

// ===================================================================

class FindAll::_Internal {
 public:
};

FindAll::FindAll(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena, is_message_owned) {
  // @@protoc_insertion_point(arena_constructor:PB.Client_Server.FindAll)
}
FindAll::FindAll(const FindAll& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:PB.Client_Server.FindAll)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData FindAll::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*FindAll::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata FindAll::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_client_5fserver_2eproto_getter, &descriptor_table_client_5fserver_2eproto_once,
      file_level_metadata_client_5fserver_2eproto[2]);
}

// ===================================================================

class FindList::_Internal {
 public:
};

FindList::FindList(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  listid_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:PB.Client_Server.FindList)
}
FindList::FindList(const FindList& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      listid_(from.listid_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:PB.Client_Server.FindList)
}

inline void FindList::SharedCtor() {
}

FindList::~FindList() {
  // @@protoc_insertion_point(destructor:PB.Client_Server.FindList)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void FindList::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void FindList::ArenaDtor(void* object) {
  FindList* _this = reinterpret_cast< FindList* >(object);
  (void)_this;
}
void FindList::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void FindList::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void FindList::Clear() {
// @@protoc_insertion_point(message_clear_start:PB.Client_Server.FindList)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  listid_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* FindList::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated int32 listId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_listid(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 8) {
          _internal_add_listid(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* FindList::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:PB.Client_Server.FindList)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated int32 listId = 1;
  {
    int byte_size = _listid_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(
          1, _internal_listid(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PB.Client_Server.FindList)
  return target;
}

size_t FindList::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:PB.Client_Server.FindList)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int32 listId = 1;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int32Size(this->listid_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<int32_t>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _listid_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData FindList::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    FindList::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*FindList::GetClassData() const { return &_class_data_; }

void FindList::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<FindList *>(to)->MergeFrom(
      static_cast<const FindList &>(from));
}


void FindList::MergeFrom(const FindList& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PB.Client_Server.FindList)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  listid_.MergeFrom(from.listid_);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void FindList::CopyFrom(const FindList& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PB.Client_Server.FindList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FindList::IsInitialized() const {
  return true;
}

void FindList::InternalSwap(FindList* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  listid_.InternalSwap(&other->listid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata FindList::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_client_5fserver_2eproto_getter, &descriptor_table_client_5fserver_2eproto_once,
      file_level_metadata_client_5fserver_2eproto[3]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Client_Server
}  // namespace PB
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::PB::Client_Server::Login* Arena::CreateMaybeMessage< ::PB::Client_Server::Login >(Arena* arena) {
  return Arena::CreateMessageInternal< ::PB::Client_Server::Login >(arena);
}
template<> PROTOBUF_NOINLINE ::PB::Client_Server::Logout* Arena::CreateMaybeMessage< ::PB::Client_Server::Logout >(Arena* arena) {
  return Arena::CreateMessageInternal< ::PB::Client_Server::Logout >(arena);
}
template<> PROTOBUF_NOINLINE ::PB::Client_Server::FindAll* Arena::CreateMaybeMessage< ::PB::Client_Server::FindAll >(Arena* arena) {
  return Arena::CreateMessageInternal< ::PB::Client_Server::FindAll >(arena);
}
template<> PROTOBUF_NOINLINE ::PB::Client_Server::FindList* Arena::CreateMaybeMessage< ::PB::Client_Server::FindList >(Arena* arena) {
  return Arena::CreateMessageInternal< ::PB::Client_Server::FindList >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
