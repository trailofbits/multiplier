#pragma once

#include <QObject>
#include <QVariant>

#include <memory>

namespace drgui {

using TokenID = std::uint64_t;
constexpr TokenID kInvalidTokenID{0};

using TokenGroupID = std::uint64_t;
constexpr TokenGroupID kInvalidTokenGroupID{0};

using TokenColorID = std::uint64_t;
constexpr TokenColorID kInvalidTokenColorID{0};

enum TokenAttribute : std::uint32_t {
  TokenAttribute_Interactive = 1,
  TokenAttribute_DisplayOnGutter = 2,
};

using TokenIDList = std::vector<TokenID>;

class TextModel final : public QObject {
  Q_OBJECT

public:
  TextModel(QObject *parent = nullptr);
  virtual ~TextModel();

  void generateTestData();

  TokenID firstTokenID() const;
  TokenID lastTokenID() const;

  TokenGroupID tokenGroupID(TokenID token_id) const;
  QString tokenData(TokenID token_id) const;
  TokenColorID tokenColor(TokenID token_id) const;
  QVariant tokenProperty(TokenID token_id, int property_id) const;
  TokenAttribute tokenAttributes(TokenID token_id) const;

  TextModel(const TextModel &) = delete;
  TextModel &operator=(const TextModel &) = delete;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

signals:
  void modelReset();
};

} // namespace drgui
